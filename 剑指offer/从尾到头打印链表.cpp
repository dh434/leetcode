#include<iostream>
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <string>

using namespace std;

struct ListNode{
    int value;
    ListNode* pNext;
};

// 利用压栈  O(2n)
void printListReversingly(ListNode* pHead){
    std::stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while(pNode!=NULL){
        nodes.push(pNode);
        pNode = pNode->pNext;
    }

    while(!nodes.empty()){
        pNode = nodes.top();
        printf("%d\t", pNode->value);
        nodes.pop();
    }

}

// 递归 O(n),但是若链表很长，会导致函数调用层级很深，从而导致函数调用栈溢出。
void printListReversingly_Recursively(ListNode* pHead){
    if(pHead!=NULL){
        if(pHead->pNext != NULL){
            printListReversingly(pHead->pNext);
        }

        printf("%d\t", pHead->value);
    }
}