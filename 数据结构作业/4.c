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

void MergeList(LinkList &LA,LinkList &LB){
    if(LA == NULL){
        return;
    }
    if(LB == NULL){
        return;
    }
    LinkList pa,pb;
    pa = LA->next;
    pb = LB->next;
    LinkList e;
    e = pb;
    while(pa){
        if(pb->data == pa->data){
            pa->next = pa->next->next;
            continue;
        }
        else{
            pb = pb->next;
            continue;
        }
    }
}

int main(){
    LinkList LA,LB;
    InitList(LA);
    InitList(LB);
    MergeList(LA,LB);
    return 0;
}
