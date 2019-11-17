/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/

//注意的是，边界条件要考虑周全，两个链表长度不一定一样，
//而且记得最后的进位


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        int t = 0;
        while(l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            t = n1 + n2 + t; //表示两个数的和加上进位
            // cout << t % 10<<endl;
            cur -> next = new ListNode(t % 10) ;
            t /= 10;
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(t) cur->next = new ListNode(1); // 进位
        return res->next;


        
    }
};