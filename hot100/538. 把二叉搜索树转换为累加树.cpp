/*
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，
使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

例如：

输入: 二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13

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
    TreeNode* convertBST(TreeNode* root) {
        int temp = 0;
        return convertBSTCore(root,temp);
    }
    
    
    TreeNode* convertBSTCore(TreeNode* root, int& cumSum){
        
        if(root == NULL)
            return root;
        
        root->right = convertBSTCore(root->right, cumSum);
         
        root->val += cumSum;
        cumSum = root->val;
        root->left = convertBSTCore(root->left, cumSum);
        
        return root;
        
    }
};