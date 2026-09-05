#include<stdio.h>
#include <stdlib.h>
typedef int ElemType ;
typedef struct node {
    ElemType data;
    struct node* next;
}Node;
//初始化链表
Node* initialNode() {
    Node*N=(Node*)malloc(sizeof(Node));
    N->data=0;
    N->next=NULL;
    return N;
}
//头插法
void insertHead(Node*L,ElemType e) {
    Node *P=(Node*)malloc(sizeof(Node));
    P->data=e;
    P->next=L->next;
    L->next=P;
}
//遍历链表
void ListNode(Node*L) {
    Node*P=L->next;
    while (P!=NULL) {
        printf("%d\n",P->data);
        P=P->next;
    }
    printf("\n");
}
//尾插法
//获取尾节点
Node* getTail(Node*L) {
    Node*P=L;
    while (P->next!=NULL) {
        P=P->next;
    }
    return P;
}
//朝尾部插入节点
Node*insertTail(Node*tail,ElemType e) {
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    tail->next=p;
     return p;
}
//朝中间插入节点
int insertNode(Node*L,int pos,ElemType e) {
    Node*p=L;
    int i=0;
    while (i<pos-1) {
        p=p->next;
        i++;
        if (p==NULL) {
            return 0;
        }
    }
    Node*n=(Node*)malloc(sizeof(Node));
    n->data=e;
    n->next=p->next;
    p->next=n;
    return 1;
}
//删除节点
int deleteNode(Node*L,int pos) {
    Node*p=L;
    int i=0;
    while (i<pos-1) {
        p=p->next;
        i++;
        if (p->next==NULL) {
            printf("寻找失败");
            return 0;
        }
    }
    if (p->next==NULL) {
        printf("无法删除");
        return 0;
    }
    Node*q=(Node*)malloc(sizeof(Node));
    q=p->next;
    p->next=q->next;
    free(q);
    return 1;
}
//获取链表的长度
int listLength(Node*L) {
    Node*p=L;
    int len=0;
    while (p!=NULL) {
        p=p->next;
        len++;
    }
    return len;

}
//释放链表
void freeLinkList(Node*L) {
    Node*p=L->next;
    Node*q;
    while (p!=NULL) {
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
}

int main() {
    Node*L=initialNode();
   Node*tail= getTail(L);
     tail=  insertTail(tail,10);
   tail= insertTail(tail,20);
  tail=  insertTail(tail,30);
    insertNode(L,2,100);
    deleteNode(L,2);
    printf("%d\n",listLength(L));
    freeLinkList(L);
    ListNode(L);
    return 0;
}