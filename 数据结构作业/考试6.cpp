#include <bits/stdc++.h>
#include <iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define Status int
using namespace std;

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void CountDegrees(BiTree T, int &leaf, int &deg1, int &deg2) {
    if (T == NULL) {
        return;
    }
    int childCount = (T->lchild != NULL) + (T->rchild != NULL);
    if (childCount == 0) {
        leaf++;
    } else if (childCount == 1) {
        deg1++;
    } else {
        deg2++;
    }
    CountDegrees(T->lchild, leaf, deg1, deg2);
    CountDegrees(T->rchild, leaf, deg1, deg2);
}

void CreateBiTree(BiTree &T) {
    int x;
    cin >> x;
    if (x == -1) {
        T = NULL;
    } else {
        T = new BiTNode();
        T->data = x;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

int main() {
    BiTree root;
    CreateBiTree(root);
    int leaf = 0;
    int deg1 = 0;
    int deg2 = 0;
    CountDegrees(root, leaf, deg1, deg2);
    printf("叶结点个数: %d\n", leaf);
    printf("度为1的结点个数: %d\n", deg1);
    printf("度为2的结点个数: %d\n", deg2);
    return 0;
}