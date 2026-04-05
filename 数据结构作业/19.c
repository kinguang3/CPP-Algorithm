//递归
#include <stdio.h>
#include <stdlib.h>
#define Status int
#define OK 1
#define ERROR 0

int Ackermann(int m,int n){
    if(m == 0){
        return n + 1;
    }
    else if(n == 0){
        return Ackermann(m - 1,1);
    }
    else{
        return Ackermann(m - 1,Ackermann(m,n - 1));
    }
}

//非递归实现






int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d",Ackermann(2,1));
    return 0;
}



