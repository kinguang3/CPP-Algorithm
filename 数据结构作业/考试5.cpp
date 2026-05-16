#include <bits/stdc++.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define Status int


typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


void CopyBiTree(BiTree &T1, BiTree T2) {
    if (T2 == NULL) {
        T1 = NULL;
    } else {
        T1 = new BiTNode();
        T1->data = T2->data;
        CopyBiTree(T1->lchild, T2->lchild);
        CopyBiTree(T1->rchild, T2->rchild);
    }
}


int main() {
    BiTree T1, T2;
    T2 = new BiTNode();
    T2->data = 5;
    T2->lchild = new BiTNode();
    T2->lchild->data = 3;
    T2->lchild->lchild = NULL;
    T2->lchild->rchild = NULL;
    T2->rchild = new BiTNode();
    T2->rchild->data = 7;
    T2->rchild->lchild = NULL;
    T2->rchild->rchild = NULL;

    CopyBiTree(T1, T2);
    return 0;
}