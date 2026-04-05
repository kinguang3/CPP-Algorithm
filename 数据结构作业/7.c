#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define Status int

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode ,*LinkList;

Status InitList(LinkList &L){
    L = LNode;
    L->next = NULL;
    return OK;
}

int Length(LinkList &l){
    int len = 0;
    while(l){
        len++;
        l = l->next;
    }
    return len;
}

void Turn(LinkList &l){
    if(l == NULL){
        return;
    }
    int length = Length(l);
    LinkList p1,p2,tmp;
    tmp = l;
    p1 = l->next;
    p2 = l->next->next;
    for(int i=0;i<=length;++i){
        p1->next = tmp;
        tmp = p1;
        p1 = p2;
        p2 = p2->next;
    }
}


int main(){
    LinkList L;
    InitList(L);
    Turn(L);
    return 0;
}