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

void Push(SqStack &S,char e){
    if(S.top - S.base == S.StackSize){
        return ERROR;
    }
    *S.top++ = e;
}

void Pop(SqStack &S,char &e){
    if(S.top == S.base){
        return ERROR;
    }
    e = *--S.top;
}

char GetTop(SqStack &S){
    if(S.top == S.base){
        return ERROR;
    }
    return *(S.top-1);
}

bool IsTurn(char *s){
    int i = (n+1)/2;
    SqStack S;
    InitStack(S);
    for(int j = 0;j<i;j++){
        Push(S,s[j]);
    }
    for(int j = i;j<n;j++){
        char e;
        e = GetTop(S);
        if(e != s[j]){
            return false;
        }
        Pop(S,e);
        
    }
    return true;
} 

int main(){
    char s[100];
    scanf("%s",s);
    n = strlen(s);
    if(IsTurn(s)){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}