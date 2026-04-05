#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE = 100
#define OK 1
#define ERROR 0
#define Status int
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;


Status InitList(LinkList &L){
    L = LNode;
    L->next = NULL;
    return OK;
}

void Rotate(LinkList &L){
    LNode *p = L->next;
    while(p->next != L){
        p = p->next;
    }
    p->next = L;
}

void Push(LinkList &L,int e){
    LinkList tmp;
    tmp->data = e;
    while(p->next != L){
        p = p->next;
    }
    p->next = tmp;
    tmp->next = L;
}

void Pop(LinkList &L,int &e){
    LinkList tmp;
    tmp = L->next;
    e = tmp->data;
    L->next = tmp->next;
    free(tmp);
}


