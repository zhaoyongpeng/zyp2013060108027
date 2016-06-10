/**
 *
 *@auther:zyp
 *
 *@time:2016/5/16
 *
 *
 *
 *�������Զ��������� inode �ṹ
 *  �������һ�Σ����Σ������μ�ӿ�
 *  �߼��� n ��Ӧ����� n
 *���룺
 *  �ļ��߼���ַ
 *���
 *  ��� inode ��ϸ��Ϣ����ӿ鲻չ����
 *  �����ַ�������ţ�����ƫ�ƣ�
 *
 *�̿��С��1KB
 *�̿�ţ�4B
 */
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct inode {
    //��������һ����������������������һ����������
    int length;
    int blockcount;
    int direct1;
    int direct2;
    int direct3;
    struct nextnode* level2node1;
    struct nextnode* level2node2;
    struct finalnode* level3node1;
};

struct nextnode {
    //��������
    int place;
    int block[256];
};

struct finalnode {
    //��������
    int place;
    struct nextnode index[256];
};

struct inode* getinode();
void outputcontroll(int physicblock, int offset,struct inode* myinode);

int main() {

    int fileaddr;
    scanf("%d", &fileaddr);

    struct inode* myinode = getinode();

    if (fileaddr > myinode->length) {
        printf("�ļ���ַ�����ļ����ȣ��˳�\n");
        exit(1);
    }

    int belongblock = (fileaddr/1024);
    int offset = fileaddr - (belongblock * 1024);
    int physicblock = 0;
    if (belongblock == 0) {
        physicblock = myinode->direct1;
    } else if (belongblock == 1) {
        physicblock = myinode->direct2;
    } else if (belongblock == 2) {
        physicblock = myinode->direct3;
    } else if (belongblock >= 3 && belongblock <= 258) {
        physicblock = myinode->level2node1->block[belongblock - 3];
    } else if (belongblock >= 259 && belongblock <= 515) {
        physicblock = myinode->level2node1->block[belongblock - 259];
    } else if (belongblock >= 516) {
        physicblock = myinode->level3node1->index[(belongblock - 516)/256].block[(belongblock - 516)%256];
    }
    outputcontroll(physicblock, offset, myinode);

}

struct inode* getinode() {
     //�������iNode��Ϣ
     int i;
    srand((unsigned)time(NULL));
    int length = rand();//�޶��ļ�����
    struct inode* myinode = (struct inode*)malloc(sizeof(struct inode));

    int blockcount = length/1024 + ((length % 1024 != 0) ? 1 : 0);

    //��ʼ��ֱ�ӿ�
    int direct1 = rand()%1000;
    int direct2 = rand()%1000;
    int direct3 = rand()%1000;

    struct nextnode* level2node1 = NULL;
    struct nextnode* level2node2 = NULL;
    struct finalnode* level3node1 = NULL;

    //��ʼ��һ�μ�ӿ�
    if (blockcount > 3) {
        level2node1 = (struct nextnode*)malloc(sizeof(struct nextnode));
        level2node1->place = rand()%1000;
        for(i = 0; i < 256; i++) {
            level2node1->block[i] = rand()%1000;
        }
    }
    if (blockcount > 258) {
        level2node2 = (struct nextnode*)malloc(sizeof(struct nextnode));
        level2node2->place = rand()%1000;
        for(i = 0; i < 256; i++) {
            level2node2->block[i] = rand()%1000;
        }
    }

    //��ʼ�����μ�ӿ�
    if (blockcount > 514) {
        level3node1 = (struct finalnode*)malloc(sizeof(struct finalnode));
        level3node1->place = rand()%1000;
        for(i = 0; i < 256; i++) {
            struct nextnode* tmp = (struct nextnode*)malloc(sizeof(struct nextnode));
            tmp->place = rand()%1000;
            int j = 0;
            for (j = 0; j < 256; j++) {
                tmp->block[j] = rand()%1000;
            }
            level3node1->index[i] = *tmp;
        }
    }

    myinode->length = length;
    myinode->blockcount = blockcount;
    myinode->direct1 = direct1;
    myinode->direct2 = direct2;
    myinode->direct3 = direct3;
    myinode->level2node1 = level2node1;
    myinode->level2node2 = level2node2;
    myinode->level3node1 = level3node1;
    return myinode;
}

void outputcontroll(int physicblock, int offset,struct inode* myinode) {

    int blockcount = myinode->blockcount;

   
    printf("input address��\n%d\n", myinode->length);
	printf("The physical address is %d block and %d offset", myinode->blockcount, offset);
    printf("The 1 level is��%d\n", myinode->direct1);
    if (blockcount >= 2)
        printf("The 2 level is��%d\n", myinode->direct2);
    if (blockcount >= 3)
        printf("The 3 level is��%d\n", myinode->direct3);
    if (blockcount >= 4)
        printf("The 2 level is��%d\n", myinode->level2node1->place);

    if (blockcount >= 515)
        printf("The 3 level is��%d\n", myinode->level3node1->place);


}

