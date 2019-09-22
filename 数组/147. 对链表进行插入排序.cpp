/*
对链表进行插入排序。


插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5

*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        
        ListNode* pNode = head->next;
        ListNode* pre = head;
        if(pre->val > pNode->val) swap(&pNode->val, &pre->val);
        pre = pNode;
        pNode = pNode->next;
        
        
        while(pNode != NULL){
            if(pNode->val > pre->val){
                pre =pNode; 
                pNode = pNode->next;
                continue;
            }
            
            if(pNode->val < head->val){
                pre->next = pNode->next;
                pNode->next = head;
                head= pNode;
                pNode = pre->next;
                continue;
            } 
            
            ListNode* temp_pre = head;
            ListNode* temp = head->next;
            while(temp != pNode && temp->val < pNode->val){
                temp = temp->next;
                temp_pre = temp_pre->next;
            } 
            pre->next = pNode->next;
            pNode->next = temp;
            temp_pre->next = pNode;
            pNode = pre->next;
        }   
        
        return head;
    }
    
    void swap(int* a, int*b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};