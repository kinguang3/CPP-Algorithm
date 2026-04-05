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

void FenZU(LinkList &LA,LinkList &LB,LinkList &LC){
    if(LA == NULL){
        return;
    }
    InitList(LB);
    InitList(LC);
    LinkList pa,pb,pc;
    pa = LA->next;
    pb = LB->next;
    pc = LC->next;
    while(pa){
        if(pa->data < 0){
            pb->data = pa->data;
            pb = pb->next;
            pa = pa->next;
        }
        else{
            pc->data = pa->data;
            pc = pc->next;
            pa = pa->next;
        }
    }
}


int main(){
    LinkList LA,LB,LC;
    InitList(LA);
    InitList(LB);
    InitList(LC);
    FenZU(LA,LB,LC);
   }
