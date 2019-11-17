/*
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.

示例 1:

输入:
    3
   / \
  9  20
    /  \
   15   7
输出: [3, 14.5, 11]
解释:
第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
注意：

节点值的范围在32位有符号整数范围内。

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


//注意溢出
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> mq;
        mq.push(root);
        
        while(!mq.empty()){
            int len = mq.size();
            double sum = 0;
            
            for(int i =0;i<len;++i){
                TreeNode* temp = mq.front();
                mq.pop();
                sum += temp->val;
                
                if(temp->left) mq.push(temp->left);
                if(temp->right) mq.push(temp->right);
            }
            
            res.push_back(sum/(double)len);
        }
        
        return res;
    }
};