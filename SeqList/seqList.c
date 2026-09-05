#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType* data;
    ElemType length;
}SeqList;
//初始化顺序表
void initialSeqList(SeqList *L) {
    L->length=0;
}
//朝尾部添加数据
int appendElem(SeqList*L,ElemType e) {
    if (L->length>=MAXSIZE) {
        printf("顺序表已达到最大尺寸");
        return 0;
    }
    L->data[L->length]=e;
    L->length++;
    return 1;
}
//遍历数据集
void listElem(SeqList *L) {
    for (int i=0;i<L->length;i++) {
        printf("%d\n",L->data[i]);
    }
}
//中间插入数据
int insertElem(SeqList*L,int pos,ElemType e) {
    if (L->length>=MAXSIZE) {
        printf("数据集已满");
        return 0;
    }
    if (pos<1||pos>L->length) {
        printf("插入位置错误");
        return 0;
    }
    for (int i=L->length-1;i>=pos-1;i--) {
        L->data[i+1]=L->data[i];
    }
    L->data[pos-1]=e;
    L->length++;
    return 1;
}
//删除数据
int deleteElem(SeqList*L,int pos,ElemType* e) {
    if (pos<1||pos>L->length) {
        printf("插入位置错误");
        return 0;
    }
    *e= L->data[pos-1];
    for (int i=pos;i<L->length;i++) {
        L->data[i-1]=L->data[i];
    }
    L->length--;
    return 1;
}
//查找数据
int searchElem(SeqList*L,int e) {
    for (int i=0;i<L->length;i++) {
        if (L->data[i]==e) {
            return i+1;
        }
    }
    return -1;
}
//动态分配内存地址的变化
SeqList* init() {
    SeqList *L=(SeqList*)malloc(sizeof(SeqList));
    L->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    L->length=0;
    return L;
}
int main(void) {
    SeqList L;
    initialSeqList(&L);
    appendElem(&L,1);
    appendElem(&L,2);
    appendElem(&L,3);
    appendElem(&L,4);
    int a;
    deleteElem(&L,2,&a);
    insertElem(&L,2,2);
    listElem(&L);
     int b= searchElem(&L,2);
    printf("%d\n",b);
    return 0;
}
