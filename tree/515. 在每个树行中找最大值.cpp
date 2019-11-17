/*
您需要在二叉树的每一行中找到最大的值。

示例：

输入: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

输出: [1, 3, 9]

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> mq;
        mq.push(root);
        
        while(!mq.empty()){
            int len = mq.size();
            int max_num = INT_MIN;
            
            for(int i =0;i<len;++i){
                TreeNode* temp = mq.front();
                mq.pop();
                if(max_num < temp->val)
                    max_num = temp->val;
                
                if(temp->left) mq.push(temp->left);
                if(temp->right) mq.push(temp->right);
            }
            
            res.push_back(max_num);
        }
        
        return res;
    }
};