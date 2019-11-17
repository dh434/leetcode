/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]2w'q'q'q'q'q

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> node_stack;
        
        vector<int> path;
        
        if(root == NULL)
            return path;
        
        TreeNode* p = root;
        while(p!=NULL || !node_stack.empty()){
            while(p!=NULL){
                node_stack.push(p);
                p = p->left;
            }
            
            if(!node_stack.empty()){
                p = node_stack.top();
                
                path.push_back(p->val);
                
                node_stack.pop();
                p = p->right;
            }
        }
        
        return path;
    }
};