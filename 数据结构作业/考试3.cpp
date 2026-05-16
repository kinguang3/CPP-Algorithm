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

void Copy(LinkList &L1, LinkList L2){
    if(L2->next == NULL){
        return;
    }
    LinkList temp = L2->next;
    LinkList tail = L1;
    while(temp != NULL){
        LinkList newNode = (LinkList)malloc(sizeof(LNode));
        newNode->data = temp->data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        temp = temp->next;
    }
}

int main(){
    LinkList L1, L2;
    InitList(L1);
    InitList(L2);
    CreateList(L2, 5); 
    Copy(L1, L2);
    return 0;
}