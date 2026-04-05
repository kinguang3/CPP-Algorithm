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


void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC){
    InitList(LC);
    struct LNode *pa,*pb,*pc;
    pa = LA->next;
    pb = LB->next;
    LC = LA;
    pc = LC;
    while(pa && pb){
        if(pa->data <= pb->data){
            pc->next = pa;
            pa = pa->next;
            pc = pc->next;
        }
        else{
            pc->next = pb;
            pb = pb->next;
            pc = pc->next;
        }
    }
    pc->next =pa?pa:pb;
   }

   int main(){
    LinkList LA,LB,LC;
    InitList(LA);
    InitList(LB);
    MergeList_L(LA,LB,LC);
   }