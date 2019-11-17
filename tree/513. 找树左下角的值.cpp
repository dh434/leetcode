/*
给定一个二叉树，在树的最后一行找到最左边的值。

示例 1:

输入:

    2
   / \
  1   3

输出:
1
 

示例 2:

输入:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

输出:
7
 

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
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL)
            return -1;
        
        queue<TreeNode*> mq;
        mq.push(root);
        int res;
        while(!mq.empty()){
            int len = mq.size();
            
            for(int i =0;i<len;++i){
                TreeNode* temp = mq.front();
                mq.pop();
                if(i == 0)
                    res = temp->val;
                
                if(temp->left) mq.push(temp->left);
                if(temp->right) mq.push(temp->right);
            }
        }
        
        return res;
    }
};