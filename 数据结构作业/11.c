#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE = 100
#define Status int
typedef struct Stack{
    int top[2],base[2];
    int *m;
    int StackSize;
}DbStack;

Status InitStack(DbStack &S){
    S.StackSize = MAXSIZE;
    top[0] = 0;
    base[0] = 0;
    top[1] = MAXSIZE;
    base[1] = MAXSIZE;
    return OK;
   }

Status Push(DbStack &S,int e){
    if(top[0] - base[0] == S.StackSize||top[1] - base[1] == S.StackSize){
        return ERROR;
    }
    if(top[0] - base[0] == S.StackSize){
        *S.top[1]++ = e;
        return OK;
    }
    else{
        *S.top[0]++ = e;
        return OK;
    }
    return OK;
}
Status Pop(DbStack &S,int &e){
    if(top[0] == base[0]||top[1] == base[1]){
        return ERROR;
    }
    if(top[0] == base[0]){
        e = *--S.top[1];
    }
    else{
        e = *--S.top[0];
    }
    return e;
}


int main(){
    DbStack S;
    InitStack(S);
    int e;
    scanf("%d",&e);
    Push(S,e);
    Pop(S,e);
    printf("%d",e);
    return 0;
}