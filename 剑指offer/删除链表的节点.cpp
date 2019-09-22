#include<iostream>
using namespace std;

struct ListNode{
    int value;
    ListNode* pNext;
};

void RemoveNode(ListNode **headNode, int value){
    if(headNode == NULL || *headNode == NULL)
        return ;
    
    ListNode * pToBeDelete = NULL;
    if((*headNode)->value == value){
        pToBeDelete  = *headNode;
        *headNode = (*headNode)->pNext;
    }else
    {
        ListNode* pNode = *headNode;
        while(pNode->pNext!=NULL && pNode->pNext->value != value)
            pNode = pNode->pNext;
        
        if(pNode->pNext!=NULL && pNode->pNext->value == value){
            pToBeDelete = pNode->pNext;
            pNode->pNext = pNode->pNext->pNext;
        }

        if(pToBeDelete!=NULL){
            delete pToBeDelete;
            pToBeDelete = NULL;
        }
    }
}
