/*
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
    vector<TreeNode*> generateTrees(int n) {
        
        if(n==0){
            vector<TreeNode*> res;
            return res;
        }
        
        vector<vector<vector<TreeNode*>>> matrix(n, vector<vector<TreeNode*>>(n));
        
        for(int i=0;i<n;++i)
            matrix[i][i].push_back(new TreeNode(i+1));
        
        for(int len = 2;len <= n;++len){
            for(int i =0;i<=n-len;++i){
                
                int j = i+len-1;    
                
                //matrix[i+1][j]
                for(int r=0;r<matrix[i+1][j].size();++r){
                    TreeNode* tempNode = new TreeNode(i+1);
                    tempNode->right = matrix[i+1][j][r];
                    matrix[i][j].push_back(tempNode);
                }
                
                //matrix[i][j-1]
                for(int r=0;r<matrix[i][j-1].size();++r){
                    TreeNode* tempNode = new TreeNode(j+1);
                    tempNode->left = matrix[i][j-1][r];
                    matrix[i][j].push_back(tempNode);
                }
                
                for(int k = i+1;k<j;++k){
                    for(int l =0; l<matrix[i][k-1].size();++l){
                        for(int r =0 ;r<matrix[k+1][j].size();++r){
                            TreeNode* tempNode = new TreeNode(k+1);
                            tempNode->left = matrix[i][k-1][l];
                            tempNode->right = matrix[k+1][j][r];
                            matrix[i][j].push_back(tempNode);
                        }
                    }
                }
                                
            }
        }
        
        return matrix[0][n-1];
    }
};