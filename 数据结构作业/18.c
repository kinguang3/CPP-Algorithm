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

void EnQueue(SqQueue &Q,int e){
    if((Q.rear + 1) % MAXSIZE == Q.front){
        return ERROR;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
}

void DeQueue(SqQueue &Q,int &e){
    if(Q.front == Q.rear){
        return ERROR;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
}