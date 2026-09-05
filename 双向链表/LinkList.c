#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct {
    ElemType data;
    Node*prev;
     Node*next;
}Node;
//初始化
Node* initial() {
    Node*L;
    L->data=0;
    L->prev=NULL;
    L->next=NULL;
    return L;
}
//头插法
void insertHead(Node*L,ElemType e) {
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->prev=L;
    if (L->next!=NULL) {
        L->next->prev=p;
    }
    p->next=L->next;
    L->next=p;

}
//找到尾部节点
Node* getTail(Node*L) {
    Node*p=L;
    while (p->next!=NULL) {
        p=p->next;
    }
    return p;
}
//尾插法
void insertTail(Node*tail,ELemType e) {
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->prev=tail;
    tail->next=p;
    p->next=NULL;
}
//删除节点
int deleteNode(Node*L,int pos) {
    Node*p=L;
    int i=0;
    while (i<pos-1) {
        p=p->next;
        i++;
        if (p==NULL) {
            return 0;
        }
    }
    if (p->next==NULL) {
        printf("要删除的位置错误");
        return 0;
    }
    Node*q=p->next;
    p->next=q->next;
    q->next->prev=p;
    free(q);
    return 1;
}
//插入节点
int insertNode(Node*L,int pos,ElemType e) {
    int i=0;
    Node*p=L;
    while (i<pos-1) {
        p=p->next;
        i++;
        if (p==NULL) {
            return 0;
        }
    }
    Node*q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next->prev=q;
    p->next=q;
    q->prev=p;
    return 1;
}
int main() {

    return 0;
}
