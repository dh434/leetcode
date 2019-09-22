#include<iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <queue>
#include <stdio.h>  
#include <time.h>  
#include <windows.h>  
#include <exception> 
using namespace std;
#include <utility>

struct ListNode{
    int value;
    ListNode* next;
};

unsigned int GetListLength(ListNode* head){
    unsigned int nLength = 0;
    ListNode* node = head;
    while(node != NULL){
        ++ nLength;
        node = node->next;
    }
    return nLength;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2){
    unsigned int nLength1 = GetListLength(pHead1);
    unsigned int nLength2 = GetListLength(pHead2);

    int lengthDiff = nLength1 - nLength2;
    
    ListNode* pListHeadLong = pHead1;
    ListNode* pListHeadShort = pHead2;
    if(nLength2 > nLength1){
        pListHeadLong = pHead2;
        pListHeadShort = pHead1;
        lengthDiff = nLength2 - nLength1;
    }

    //先在长的走几步
    for(int i =0 ;i<lengthDiff;++i)
        pListHeadLong = pListHeadLong->next;

    while((pListHeadLong!=NULL) && (pListHeadShort!=NULL) && (pListHeadLong!=pListHeadShort)){
        pListHeadLong = pListHeadLong->next;
        pListHeadShort = pListHeadLong->next;
    }

    ListNode* pFirstCommonNode = pListHeadLong;

    return pFirstCommonNode;
}