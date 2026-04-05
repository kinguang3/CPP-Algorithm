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

void Pop(LinkList &l,int mink,int maxk){
    if(mink > maxk||l == NULL){
        return;
    }
    while(l){
        if(l->data < mink && l->data > maxk){
            l->next = l->next->next;
        }
    }
}

int main(){
    LinkList L;
    int mink,maxk;
    InitList(L);
    scanf("%d %d",&mink,&maxk);
    Pop(L,mink,maxk);
    return 0;
}