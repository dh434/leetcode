/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

*/


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL||head->next == NULL )
            return true;
        
        
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!= NULL && fast->next!=NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        pre->next = NULL;
        
        //reverse
        pre = slow;
        ListNode* cur = slow->next;
        pre->next = NULL;
        
        while(cur!=NULL){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur= temp;
        }
        
        //
        ListNode* new_head = pre;
        ListNode* old_head = head;
        cout<< new_head->val<<" "<<old_head->val <<endl;
        while( new_head!=NULL && old_head!=NULL && old_head->val == new_head->val){
            new_head = new_head->next;
            old_head = old_head->next;
        }
        
        if(new_head==NULL || old_head==NULL)
            return true;
        else
            return false;
    }
};