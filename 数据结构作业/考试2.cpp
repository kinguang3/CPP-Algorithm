#include <bits/stdc++.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define Status int

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode ,*LinkList;


void CreateList(LinkList &L, int n){
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LinkList tail = L;
    for(int i = 0; i < n; i++){
        LinkList newNode = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

Status InitList(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
}

Status Judge(LinkList L){
    if(L->next == NULL){
        return ERROR;
    }
    LinkList temp = L->next;
    L = L->next->next;
    while(L != NULL){
        if(L->data >= temp->data){
            L = L->next;
            temp = temp->next;
            continue;
        }
        else{
            return ERROR;
        }
    }
    return OK;
}


int main(){
    LinkList L;
    InitList(L);
    CreateList(L, 5);
    Judge(L);
    return 0;
}