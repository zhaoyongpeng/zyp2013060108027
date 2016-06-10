/**
 *@auther:zyp
 *
 *@time 2016.6.3
 *
 *@discription:共享缓冲区中放置一个数字，取值范围为[0, 10]，初值为0。生产者将此值加1，消费者将此值减1。启动一组生产者进程和一组消费者进程
 *     同一个数据文件为缓冲区；
 *
 *  此进程为消费者进程；
 */

#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<stdlib.h>

#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <sys/file.h>

#define running 1
#define waiting 2

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <id>\n",argv[0]);
        exit(1);
    }

    int state = running;
    int id = atoi(argv[1]);

    sem_t* emptysem = sem_open("emptysem", O_CREAT , S_IRWXO, 10);
    sem_t* fullsem = sem_open("fullsem", O_CREAT, S_IRWXO, 0);

    while (1) {
        if (sem_trywait(fullsem) == 0) {

            int sharedbuffer;

            FILE* bufferfile = NULL;
            bufferfile = fopen("buffer.txt", "r+");

            if (flock(bufferfile->_fileno, LOCK_EX) == 0) {//文件互斥所
                char mystring[20];
                fgets(mystring , 20 , bufferfile);
                sharedbuffer = atoi(mystring);
                int tmp = sharedbuffer;
                sharedbuffer--;
                char buff[10];
                sprintf(buff, "%d", sharedbuffer);
                printf("%s\n", buff);
              //  read(bufferfile->_fileno, &sharedbuffer, sizeof(int));
                if (state == running) {
                    printf("consumer %d : %d -> %d\n", id, tmp, sharedbuffer);
                    rewind(bufferfile);
                    fputs(buff, bufferfile);
                }
                if (state == waiting) {
                    printf("consumer %d :(resumn) %d -> %d\n", id, tmp, sharedbuffer);
                    state = running;
                    rewind(bufferfile);
                    fputs(buff, bufferfile);
                }
                fclose(bufferfile);
                flock(bufferfile->_fileno, LOCK_UN);
                sem_post(emptysem);
            }
        } else {
            state = waiting;
            printf("consumer %d: waiting, can't go into critical section\n", id);
        }
        sleep(1);
    }

        return;
}
