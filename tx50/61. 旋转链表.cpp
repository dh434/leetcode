/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

*/

// 注意要把len也算上，就是考虑看k>n的情况

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0 || head->next==NULL)
            return head;
        
        ListNode* tail = head;
        int len = 0;
        while(tail->next!=NULL){
            tail = tail->next;
            len++;
        } 
        len++;
        
        // cout<<tail->val;
        ListNode* pHead = head;
        tail->next = pHead;
        
        for(int i = 0;i<len-k%len-1;++i)
            pHead = pHead->next;
        
        ListNode* newHead = pHead->next;
        pHead->next = NULL;
        return newHead;
    }
};