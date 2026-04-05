#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define Status int
typedef struct{
    int *base;
    int front;
    int rear;
}SqQueue;


Status InitQueue(SqQueue &Q){
    Q.base = int [MAXSIZE];
    if(!Q.base){
        return ERROR;
    }
    Q.front = Q.rear = 0;
    return OK;
}

bool IsEmpty(SqQueue &Q){
    if(Q.front == Q.rear){
        bool tag = true;
    }
    else{
        bool tag = false;
    }
    return tag;
}

bool IsFull(SqQueue &Q){
    if((Q.rear + 1) % MAXSIZE == Q.front){
        bool tag = true;
    }
    else{
        bool tag = false;
    }
    return tag;
}


void EnQueue(SqQueue &Q,int e){
    if(IsFull(Q)){
        return ERROR;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
}

void DeQueue(SqQueue &Q,int &e){
    if(IsEmpty(Q)){
        return ERROR;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
}