#include <bits/stdc++.h>
using namespace std;
struct  ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//*head在这里是首元节点
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* huge = new ListNode(0);
        ListNode* pa = small;
        ListNode* pb = huge;
        ListNode* p = head;
        while(p != nullptr)
        {
            if(p->val<x)
            {
                small->next = p;
                small = small->next;
            }
            else
            {
                huge->next = p;
                huge = huge->next;
            }
            p = p->next;
        }
        huge->next = nullptr;
        small->next = pb->next;
        ListNode* newnode = pa->next;
        return newnode;
    }
};