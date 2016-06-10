/**
 * @auther zyp
 *
 * @time 2016.6.3
 *
 * @discription:共享缓冲区中放置一个数字，取值范围为[0, 10]，初值为0。生产者将此值加1，消费者将此值减1。启动一组生产者进程和一组消费者进程
 * 	同一个数据文件为缓冲区；
 *
 * 此进程为生产者进程；
 **/
#include<stdio.h>
#include<semaphore.h>

#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

#include<fcntl.h>           /* For O_* constants */
#include<sys/stat.h>        /* For mode constants */

#include<error.h>

//sem_t emptysem;
//sem_t fullsem;

int main() {

	int producerNum =1, consumerNum=1, i;
	printf("input producerNum and consumerNum:\n");
	scanf("%d%d", &producerNum, &consumerNum);

	sem_unlink("emptysem");
	sem_unlink("fullsem");

	sem_open("emptysem", O_CREAT, S_IRWXO, 10);
	sem_open("fullsem", O_CREAT, S_IRWXO, 0);

	for (i = 0; i < producerNum; i++) {
        char buff[10];
        sprintf(buff, "%d", i);
        printf("%s\n", buff);
		if (fork() == 0) {
			if(execl("./producer", "producer", buff, NULL) < 0) {
				perror("producer failed");
			}
		}
	}
	for (i = 0; i < consumerNum; i++) {
        char buff[10];
        sprintf(buff, "%d", i);
        printf("%s\n", buff);
        if (fork() == 0) {
            if(execl("./consumer", "consumer", buff, NULL) < 0) {
				perror("consumer failed");
			}
        }
    }

}
