#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE = 100
#define OK 1
#define ERROR 0
#define Status int
typedef struct Stack{
    char *top;
    char *base;
    int StackSize;
}SqStack;
int n;
int a[n];

Status InitStack(SqStack &S){
    S.base = char [MAXSIZE];
    if(!S.base){
        return ERROR;
    }
    S.top = S.base;
    S.StackSize = MAXSIZE;
    return OK;
}

void Push(SqStack &S,int e){
    if(S.top - S.base == S.StackSize){
        return ERROR;
    }
    *S.top++ = e;
}

void Pop(SqStack &S,int e){
    if(S.top == S.base){
        return ERROR;
    }
    e = *--S.top;
}

int GetTop(SqStack &S){
    if(S.top == S.base){
        return ERROR;
    }
    return *(S.top-1);
}


void Judge(SqStack &S,int *a,int n){
    for(int i = 0;i<n;i++){
        if(a[i]!=-1){
            Push(S,a[i]);
        }
        else{
            int e = GetTop(S);
            printf("%d ",e);
            Pop(S,e);
        }
    }
}

int main(){
    SqStack S;
    InitStack(S);
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Judge(S,a,n);
}