#include <bits/stdc++.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define Status int


typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTNode* FindMinNode(BiTree T) {
    if (T == NULL) return NULL;
    BiTNode* min_node = T;
    BiTNode* left_min = FindMinNode(T->lchild);
    BiTNode* right_min = FindMinNode(T->rchild);
    if (left_min && left_min->data < min_node->data) min_node = left_min;
    if (right_min && right_min->data < min_node->data) min_node = right_min;
    return min_node;
}

int main() {
    BiTNode* root = new BiTNode();
    root->data = 5;
    root->lchild = new BiTNode();
    root->lchild->data = 3;
    root->lchild->lchild = NULL;
    root->lchild->rchild = NULL;
    root->rchild = new BiTNode();
    root->rchild->data = 7;
    root->rchild->lchild = NULL;
    root->rchild->rchild = NULL;

    BiTNode* minNode = FindMinNode(root);
    if (minNode) {
        printf("最小值节点的值: %d\n", minNode->data);
    }
    return 0;
}

