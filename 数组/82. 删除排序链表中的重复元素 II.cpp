/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

*/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = cur;
        while(cur != NULL){
            
            if(cur->next != NULL && cur->next->val == cur->val){
                int val = cur->val;
                ListNode* start = cur;
                while(cur != NULL && cur->val == val) cur = cur->next;
                
                if(start != head){
                    pre->next = cur;
                }else{
                    head = cur;
                    pre = head;
                }
                
            }else{
                pre = cur;
                cur = cur->next;
            }
            
            
        }
        
        return head;
        
    }
};