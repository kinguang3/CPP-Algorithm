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

bool isNumber(char *c){
    return strlen(c) > 1 || *c >= '0' && c <= '9';
}

int evalRPN(char **tokens,int tokensSize){
    SqStack S;
    InitStack(S);
    int top = 0;
    for(int i = 0;i < tokensSize;i++){
        if(isNumber(tokens[i])){
            Push(S,atoi(tokens[i]));
        }
        else{
            int b = atoi(tokens[top--]);
            int a = atoi(tokens[top--]);
            if(strcmp(tokens[i],"+") == 0){
                Push(S,a+b);
            }
            else if(strcmp(tokens[i],"-") == 0){
                Push(S,a-b);
            }
            else if(strcmp(tokens[i],"*") == 0){
                Push(S,a*b);
            }
            else if(strcmp(tokens[i],"/") == 0){
                Push(S,a/b);
            }
        }
    }
    int res = *S.top--;
    return res;
}


int main(){
    InitStack(S);
    char tokens[100][100];
    int tokensSize = 0;
    while(scanf("%s",tokens[tokensSize]) == 1){
        tokensSize++;
    }
    int res = evalRPN(tokens,tokensSize);
    printf("%d",res);
    return 0;
}