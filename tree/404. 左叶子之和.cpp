/*
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesCore(root,0);
    }
    
    int sumOfLeftLeavesCore(TreeNode* root, int flag){
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL){
            return flag == 1?root->val:0;
        }
        
        int left = sumOfLeftLeavesCore(root->left, 1);
        int right = sumOfLeftLeavesCore(root->right, 0);
        
        return left+right;
    }
};