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


bool Judge(char *s){
    SqStack S;
    InitStack(S);
    int n = strlen(s);
    for(int i = 0;i < n;i++){
        if(s[i] == 'I'){
            Push(S,s[i]);
        }
        else if(s[i] == 'O'){
            if(S.top == S.base){
                return false;
            }
            Pop(S,s[i]);
        }
    }
    return true;
}


int main(){
    char s[100];
    scanf("%s",s);
    bool res = Judge(s);
    if(res){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}