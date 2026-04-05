#include <stdio.h>
#include <stdlib.h>
#define Status int
#define OK 1
#define ERROR 0
typedef struct{
    int data;
    struct LNode *next;
}LNode,*LinkList;

Status InitList(LinkList &L){
    L = LNode;
    L->next = NULL;
    return OK;
}

int Max(LinkList L){
    if(L->next == NULL){
        return ERROR;
    }
    int max = L->next->data;
    while(L != NULL){
        if(L->next->data > max){
            max = L->next->data;
        }
        L = L->next;
    }
    return max;
   }


int Num(LinkList L){
    if(L->next == NULL){
    return ERROR;
    }
    int num = 0;
    while(L != NULL){
        num++;
        L = L->next;
    }
    return num;
}


int Avg(LinkList L){
    if(L->next == NULL){
        return ERROR;
    }
    int sum = 0;
    while(L != NULL){
        sum += L->next->data;
        L = L->next;
    }
    return sum / Num(L);
}

int main(){
    LinkList L;
    InitList(L);
    return 0;
}