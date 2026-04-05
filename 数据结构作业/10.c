#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define Status int
int item;


typedef struct LNode{
    int data;
    struct LNode *next;
}LNode ,*LinkList;

Status InitList(LinkList &L){
    L = LNode;
    L->next = NULL;
    return OK;
}

void Pop(LinkList &l,int item){
    if(l == NULL){
        return;
    }
    LinkList p = l;
    while(p){
        if(p->data == item){
            p->next = p->next->next;
        }
        p = p->next;
    }
}


int main()(){
    LinkList L;
    InitList(L);
    scanf("%d",&item);
    Pop(L,item);
    return 0;