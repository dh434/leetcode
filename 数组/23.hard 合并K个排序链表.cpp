/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

*/

// 两两合并，归并法

//慢
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        ListNode* cur = &head;
        bool found  = true;
        while(found){
            found = false;
            
            int min_num = INT_MAX;
            int index;
            for(int i = 0;i<lists.size();++i){
                if(lists[i] != NULL && lists[i]->val < min_num){
                    found = true;
                    min_num = lists[i]->val;
                    index = i;
                }
            }
            
            
            if(found){
                cur->next = lists[index];
                lists[index] = lists[index]->next;
                cur = cur->next;
            }
        }
        
        return head.next;
        
    }


// 归并

 ListNode* mergeKLists(vector<ListNode*>& lists, int begin, int end) {
        if (end < begin) return NULL;
        if (end == begin) return lists[begin];

        int mid = (begin + end) / 2;
        auto p1 = mergeKLists(lists, begin, mid);
        auto p2 = mergeKLists(lists, mid + 1, end);

        ListNode head(0);
        ListNode* cur = &head;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }

        if (p1) cur->next = p1;
        else if (p2) cur->next = p2;
        
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }