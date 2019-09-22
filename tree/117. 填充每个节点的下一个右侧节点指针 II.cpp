/*
从满二叉树到普通二叉树


思路：
用一个dummy节点来串起来，最后会自动释放
太强了
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

//https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/


class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        
        Node* cur = root;
        while(cur != NULL){
            Node* dummy = new Node();
            dummy->next = NULL;
            Node* tail = dummy;
            while(cur!=NULL){
                if(cur->left != NULL){
                    tail->next = cur->left;
                    tail = tail->next;
                }
                
                if(cur->right != NULL){
                    tail->next = cur->right;
                    tail = tail->next;
                }
                cur = cur->next;
            }
            cur = dummy->next;
        }
        
        return root;
    }
};