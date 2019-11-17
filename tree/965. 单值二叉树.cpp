/*
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。
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
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL)
            return true;
        
        int num = root->val;
        return isUnivalTreeCore(root, num);
    }
    
    bool isUnivalTreeCore(TreeNode* root, int num){
        if(root == NULL)
            return true;
        
        if(root->val != num)
            return false;
        
        return isUnivalTreeCore(root->left, num) && isUnivalTreeCore(root->right, num);
    }
};