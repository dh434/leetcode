/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深拷贝。 

 

示例：



输入：
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

解释：
节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
 

提示：

你必须返回给定头的拷贝作为对克隆列表的引用。

*/

// 用map记录原节点和克隆节点的对应关系


//有多种方法，剑指offer的题

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return nullptr;
        
        map<Node*,Node*> mp;
        
        Node* mHead = new Node(head->val, NULL, NULL);
        
        // if(head->next == NULL)
        //     return mHead;
        
        mp[head] = mHead;
        Node* my_pre = mHead;
        Node* cur = head->next;
          
        while(cur!=NULL){
            Node* temp = new Node(cur->val, NULL, NULL);
            
            my_pre->next = temp;
            mp[cur] = temp;
            
            my_pre = my_pre->next;
            cur = cur->next;
        }
        
        
        cur = head;
        Node* my_cur = mHead;
        while(cur!=NULL){
            // cout<<cur->val<<endl;
            if(cur->random != NULL){
                my_cur->random = mp[cur->random];
            }
            
            cur = cur->next;
            my_cur = my_cur->next;
        }
        
        return mHead;
    }
};