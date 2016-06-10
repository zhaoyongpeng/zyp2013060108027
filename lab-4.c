/**
 *
 *@auther:zyp
 *
 *@time:2016/5/16
 *
 *
 *
 *条件：自定义混合索引 inode 结构
 *  必须包括一次，二次，和三次间接块
 *  逻辑块 n 对应物理块 n
 *输入：
 *  文件逻辑地址
 *输出
 *  输出 inode 详细信息（间接块不展开）
 *  物理地址（物理块号，块内偏移）
 *
 *盘块大小：1KB
 *盘块号：4B
 */
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct inode {
    //柏阔三个一次索引，两个两次索引，一个三次索引
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
    //二次索引
    int place;
    int block[256];
};

struct finalnode {
    //三次索引
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
        printf("文件地址大于文件长度，退出\n");
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
     //随机生成iNode信息
     int i;
    srand((unsigned)time(NULL));
    int length = rand();//限定文件长度
    struct inode* myinode = (struct inode*)malloc(sizeof(struct inode));

    int blockcount = length/1024 + ((length % 1024 != 0) ? 1 : 0);

    //初始化直接块
    int direct1 = rand()%1000;
    int direct2 = rand()%1000;
    int direct3 = rand()%1000;

    struct nextnode* level2node1 = NULL;
    struct nextnode* level2node2 = NULL;
    struct finalnode* level3node1 = NULL;

    //初始化一次间接块
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

    //初始化二次间接块
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

   
    printf("input address：\n%d\n", myinode->length);
	printf("The physical address is %d block and %d offset", myinode->blockcount, offset);
    printf("The 1 level is：%d\n", myinode->direct1);
    if (blockcount >= 2)
        printf("The 2 level is：%d\n", myinode->direct2);
    if (blockcount >= 3)
        printf("The 3 level is：%d\n", myinode->direct3);
    if (blockcount >= 4)
        printf("The 2 level is：%d\n", myinode->level2node1->place);

    if (blockcount >= 515)
        printf("The 3 level is：%d\n", myinode->level3node1->place);


}

