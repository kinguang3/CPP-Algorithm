#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define Status int
int n;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode ,*LinkList;

Status InitList(LinkList &L){
    L = LNode;
    L->next = NULL;
    return OK;
}

int Max(LinkList &l){
    if(l == NULL){
        return ERROR;
    }
    int max = l->data;
    for(int i = 0;i<n;i++){
        if(l->data > max){
            max = l->data;
        }
        l = l->next;
    }
    return max;
}

int main(){
    LinkList L;
    InitList(L);
    scanf("%d",&n);
    int max = Max(L);
    printf("%d",max);
    return 0;
}