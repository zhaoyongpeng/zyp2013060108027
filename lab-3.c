/**
 *@auther:лԨ
 *
 *@time:2016/5/11
 *
 *level + 1
 *������64λ��ַ�ռ�
 *  ���룺
 *      ҳ��¼��С���� 4Byte��
 *      ҳ��С���� 4KB��
 *      ҳ�������磬2��ʾ2��ҳ��n��ʾn��ҳ��
 *      �߼���ַ��ʮ�����ƣ�
 *����������ַ�������ţ�����ƫ�ƣ�
 *˵����ҳ�����������Ϊ������֤�����߼�ҳ�� n ��������Ϊ n��
 *
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ADDRSPACEBIT 32

int mapdec(char* str);
int btoi(char* src);
char* itob(int src);
int xtoi(char src);
char itox(int i);
char* bmapo(char* src, char* disformat);
char* substring(char* src, int start, int end);
char* getpaddr(int level, int recordbit, int pagebit, char* logiaddr);

int main() {

    char record[20];//ҳ�����С
    char page[20];//ҳ��С
    int level = 0;//����
    char* logicaddr = (char*)malloc(12 * sizeof(char));//�߼���ַ������0x12345678H;
    scanf("%s", record);
    scanf("%s", page);
    scanf("%d", &level);
    scanf("%s", logicaddr);
    int recordbit = mapdec(record);
    int pagebit = mapdec(page);
    char* tmp = substring(logicaddr, 2, strlen(logicaddr));
    int offset = btoi(substring(bmapo(tmp, "b"), ADDRSPACEBIT - 1 - pagebit, ADDRSPACEBIT - 1));
    char* physicaddr = getpaddr(level, recordbit, pagebit, tmp);
    printf("�߼���ַ(%s)����Ӧ�������ַ��:%s\n", logicaddr, physicaddr);
    printf("����ƫ��:%d�ֽ�\n", offset);
    return 0;
}

//����ָ�����㣬�������
//���ַ����������λ��
int mapdec(char* str) {
    int separate = 0;
    int i;
    char* key = "BbKkMmGgTtPp";
    if (strlen(str) == (separate = strcspn(str, key))) {
        printf("error: �Ƿ�����");
        exit(1);
    }
    char* num = (char*)malloc((separate + 1)*sizeof(char));
    memcpy(num, str, separate*sizeof(char));
    num[separate] = '\0';
    int tmp = atoi(num);
    int rnum = 0;
    while (tmp/2 != 0) {
        rnum++;
        if (tmp%2 != 0 && tmp > 2) {
            printf("error: δ����");
            exit(1);
        }
        tmp = tmp/2;
        if(tmp == 1)
            rnum++;
    }
    char* lable = (char*)malloc((strlen(str) - separate + 1)*sizeof(char));
    memcpy( num, str, separate*sizeof(char));
    num[separate] = '\0';
    for (i = 0; i < strlen(str) - separate; i++) {
        lable[i] = str[separate + i];
    }
    lable[strlen(str) - separate] = '\0';
    if (!strcmp(lable, "Byte") || !strcmp(lable, "byte")) {
        return rnum;
    } else if (!strcmp(lable, "Kb") || !strcmp(lable, "KB") || !strcmp(lable, "kb") || !strcmp(lable, "kB")) {
        return rnum + 10;
    } else if (!strcmp(lable, "Mb") || !strcmp(lable, "MB") || !strcmp(lable, "mb") || !strcmp(lable, "mB")) {
        return rnum + 20;
    } else {
        printf("error: �Ƿ�����");
        exit(1);
    }
}

char* getpaddr(int level, int recordbit, int pagebit, char* logiaddr) {
    ///����ҳ��
    int numppage = pow(2, pagebit-recordbit);
    //һ��ҳ��洢��Ŀ
    int level1len = ADDRSPACEBIT - pagebit - (level - 1) * recordbit;
    double level1num = 0;
    int i = 0, j = 0, k = 0;
    for (i = 0; i < level1len; i++) {
        level1num += pow(2, i);
    }
    //��ҳ��洢��Ŀ
    //ÿһ��ҳ����
    long int* numplevel = (long int*)malloc(level * sizeof(long int));
    long int totalnum = level1num;
    numplevel[0] = level1num;
    for (i = 1; i < level; i++) {
        totalnum += numplevel[i - 1] * 1024;
        numplevel[i] = totalnum - numplevel[i - 1];
    }
    int logiclen = ADDRSPACEBIT - pagebit;
    int MAX = 0;
    for (i = 0; i < logiclen; i++) {
        MAX += pow(2, i);
    }
    //����ҳ��
    srand((unsigned)time(NULL));
    int* page = (int *)malloc(totalnum * sizeof(int));
    int p = 0;//����ָ��
    i = 0;
    while(i < level) {
        if (i == 0) {
            for (j = 0; j < numplevel[0]; j++) {
                page[p] = level1num + (j - 1) * numppage;
                p++;
            }
        } else if (i == level - 1) {
            for (j = 0; j < numplevel[i]; j++) {
                page[p] = rand()%MAX;     ///question
                p++;
            }
        } else {
            for (j = 0; j < numplevel[i]; j++) {
                int offset = 0;
                for (k = 0; k < i - 1; k++) {
                    offset += numplevel[k];
                }
                page[p] = offset;     ///question
                p++;
            }
        }
        i++;
    }

     ///��ѯ
    int ptr = 0;//��ѯָ��
    char* bits = bmapo(logiaddr, "b");
    int endlevel1 = ADDRSPACEBIT - pagebit - (level - 1) * recordbit;
    char* level1 = (char*)malloc((endlevel1 - 0 + 1) * sizeof(char));
    memcpy(level1, bits, endlevel1 - 0);
    level1[endlevel1 - 0] = '\0';
    ptr = page[btoi(level1)];//���
    for (i = 0; i < level - 1; i++) {
        char* level = substring(bits, i * pagebit + endlevel1, (i + 1) * pagebit + endlevel1);
        ptr = page[btoi(level) + ptr];//���
    }

    char *temp = itob(ptr);
    temp = bmapo(temp, "x");
    char result[64] = "0x";
    strncat(result, temp, strlen(temp));
    return result;
}

int btoi(char* src) {
    //������ת����
    int a = 0, i = 0;
    int len = strlen(src);
    for (i = 0; i < len; i++) {
        if (!(src[len - 1 - i] - '0' == 0 || src[len - 1 - i] - '0' == 1)) {
             printf("error: �Ƿ���������");
            exit(1);
        }
        a += (src[len - 1 - i] - '0') * pow(2, i);
    }
    return a;
}

int xtoi(char src) {
    //������ת����
    if (src >= '0' && src <= '9') {
        return src - '0';
    } else if (src >= 'a' && src <= 'f') {
        return src - 'a' + 10;
    } else if (src >= 'A' && src <= 'F') {
        return src - 'A' + 10;
    } else {
        printf("error: �Ƿ�ʮ��������");
        exit(1);
    }
}

char itox(int i) {
    //����תʮ������
    if (i < 10 && i >= 0) {
        return (char)(i + '0');
    } else if (i < 16 && i >= 10) {
        return (char)(i + 'a' - 10);
    } else {
        printf("error: �޷�ת��");
        exit(1);
    }
}

char* itob(int src) {
    //����ת������,ֻ֧��64λ����
    char* bits = (char*)malloc(64 * sizeof(char));
    memset(bits,'0', 64);
    int quotient = src;//��
    int remainder = 0;//����
    int i = 63;//�洢λ
    bits[i--] = '\0';
    do {
        remainder = quotient % 2;
        quotient = quotient / 2;
        bits[i--] = (char)(remainder + '0');
    } while (quotient != 0 || i == 0);
    char* ret = strchr(bits,'1');
    return ret;
}

char* bmapo(char* src, char* disformat) {
    //��������ʮ�������໥ת��
    int i = 0;
    char* start = src;
    if (!strcmp(disformat, "x")) {
        char* dis;
        int offset = 0;
        if ((offset = strlen(src) % 4) != 0) {
            dis = (char*)malloc(strlen(src) / 4 + 2);
            memset(dis,'0', strlen(src) / 4 + 2);
            dis[strlen(src) / 4 + 1] = '\0';
        } else {
            dis = (char*)malloc(strlen(src) / 4 + 1);
            memset(dis,'0', strlen(src) / 4 + 1);
            dis[strlen(src) / 4] = '\0';
        }
        int j = strlen(src) - 1;
        for(i = strlen(dis) - 1; i >= 0; i--) {
            int tmp = 0;
            if (j >= 0) tmp += src[j--] - '0';
            if (j >= 0) tmp += 2 * (src[j--] - '0');
            if (j >= 0) tmp += 4 * (src[j--] - '0');
            if (j >= 0) tmp += 8 * (src[j--] - '0');
            dis[i] = itox(tmp);
        }
        return dis;
    } else if (!strcmp(disformat, "b")) {
        char* dis = (char*)malloc((strlen(src) * 4 + 1)* sizeof(char));
        memset(dis,'0', strlen(src) * 4 + 1);
        dis[strlen(src) * 4] = '\0';
        for (i = 0; i < strlen(src) * 4; i += 4) {
            int tmp = xtoi(*start);
            start++;
            if (tmp / 8 > 0) {
                dis[i] = '1';
                tmp -= 8;
            }
            if (tmp / 4 > 0) {
                dis[i + 1] = '1';
                tmp -= 4;
            }
            if (tmp / 2 > 0) {
                dis[i + 2] = '1';
                tmp -= 2;
            }
            if (tmp / 1 > 0) dis[i + 3] = '1';
        }
        return strchr(dis,'1');
    } else {
        printf("error: �Ƿ�����ת��");
        exit(1);
    }
}

char* substring(char* src, int start, int end) {
    int i = 0;
    char* ret = (char*)malloc((end - start + 1) * sizeof(char));
    ret[end - start] = '\0';
    for (i = 0; i < end - start; i++) {
        ret[i] = src[start + i];
    }
    return ret;
}
