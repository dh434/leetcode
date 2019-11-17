/*
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:

2
示例 2:

输入:

              1
             / \
            4   5
           / \   \
          4   4   5
输出:

2
注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。

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
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int res = 0;
        vector<int> temp = longestUnivaluePathCore(root,res);
        return res;
    }
    
    vector<int> longestUnivaluePathCore(TreeNode* root, int &res){
        
        if(root == NULL)
            return {};
        
        vector<int> cur = {root->val , 0};
        vector<int> left = {0,0};
        vector<int> right = {0,0};
        
        
        if(root->left != NULL){
            left = longestUnivaluePathCore(root->left, res);
            if(root->left->val == root->val)
                cur[1] = max(cur[1], left[1]+1);
        }
        
        if(root->right != NULL){
            right = longestUnivaluePathCore(root->right, res);
            if(root->right->val == root->val)
                cur[1] = max(cur[1], right[1]+1);
        }
        
        res = max(res, cur[1]);
        
        
        if(root->left != NULL && root->right != NULL && root->right->val == root->left->val && root->left->val == root->val)
            res = max(res, left[1]+right[1]+2);
        
        return cur;
        
    }
    
};

//best

class Solution {
public:
    int ret;
    int longestUnivaluePath(TreeNode* root) {
        
        recursion(root);
        return ret;
         
    }

    int recursion(TreeNode* root){
        if(root==NULL) return 0;

        int left=recursion(root->left);
        int right=recursion(root->right);

        left=(root->left!=NULL && root->val==root->left->val)? left+1:0;
        right=(root->right!=NULL && root->val==root->right->val)? right+1:0;

        ret=ret>(left+right)? ret:(left+right);
        return left>right? left:right;
    }


};