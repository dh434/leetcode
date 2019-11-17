/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyNode(0);
        dummyNode.next = head;
        
        auto p = head;
        int length = 0;
        while(p){
            ++length;
            p = p->next;
        }
        
        for(int i = 1;i<length;i<<=1){
            auto cur = dummyNode.next;
            auto tail = &dummyNode;
            while(cur){
                auto left = cur;
                auto right = cut(left, i);
                cur = cut(right,i);

                tail->next = merge(left,right);
                while(tail->next!=NULL)
                    tail = tail->next;
            }
            
        }
        
        return dummyNode.next;
        
    }
    
    
    ListNode* cut(ListNode* head, int count){
        ListNode* p = head;
        while(--count && p!=NULL){
            p = p->next;
        }
        
        if(p == NULL)
            return nullptr;
        
        ListNode* tmp = p->next;
        p->next = NULL;
        return tmp;
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode head(0);
        auto p = &head;
        
        while(left && right){
            if(left->val < right->val){
                p->next = left;
                p = p->next;
                left = left->next;
            }else{
                p->next = right;
                p= p->next;
                right = right->next;
            }
        }
        
        p->next = left?left:right;
        return head.next;
    }
};

// 使用快慢指针划分链表
//递规
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode fast = head.next, slow = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode tmp = slow.next;
        slow.next = null;
        ListNode left = sortList(head);
        ListNode right = sortList(tmp);
        ListNode h = new ListNode(0);
        ListNode res = h;
        while (left != null && right != null) {
            if (left.val < right.val) {
                h.next = left;
                left = left.next;
            } else {
                h.next = right;
                right = right.next;
            }
            h = h.next;
        }
        h.next = left != null ? left : right;
        return res.next;
    }
}

