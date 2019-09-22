/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

*/


// 巧妙运用c++ 的引用传参
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> res;
        vector<int> path;
        pathSum(root,sum,res,path);
        return res;
    }
    
    void pathSum(TreeNode* root, int sum,vector<vector<int>> &res, vector<int>& path) {
        if(root == NULL)
            return;
        
        int val = root->val;
        path.push_back(val);
        if(val == sum && root->left == NULL && root->right == NULL){
            vector<int> temp(path);
            res.push_back(temp);
        }
        
        if(root->left!= NULL)
            pathSum(root->left, sum-val, res,path);
        
        if(root->right!= NULL)
            pathSum(root->right, sum-val, res,path);
        
        path.pop_back();
        return;
    }
};