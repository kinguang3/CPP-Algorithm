#include <bits/stdc++.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define Status int
using namespace std;

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

int main(){
    int x;
    cin >> x;
    LinkList L;
    InitList(L);
    CreateList(L, 5);
    if(L->data == x){
        printf("Found");
    }
    else{
        L = L -> next;
    }
    return 0 ;
}