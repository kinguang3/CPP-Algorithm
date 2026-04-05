#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define Status int

typedef struct DuLNode{
    int data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode ,*DuLinkList;

Status InitList(DuLinkList &L){
    L = DuLNode;
    L->next = NULL;
    return OK;
}

DuLinkList Find(DuLinkList &l,int i){
    if(l == NULL){
        return NULL;
    }
    DuLinkList p = l;
    while(p){
        if(p->data == i){
            return p;
        }
        p = p->next;
    }
    return NULL;
}


void Change(DuLinkList &l,int i){
    if(l == NULL){
        return;
    }
    DuLinkList p = Find(l,i);
    if(p == NULL){
        return;
    }
    p->prior->prior->next = p->next;
    p->next->prior = p->prior->prior;
    p->prior->next = p->next->next;
    p->next->next->prior = p;
    p->prior->prior = p;
}

int main(){
    DuLinkList L;
    InitList(L);
    int i;
    scanf("%d",&i);
    Change(L,i);
    return 0;
}