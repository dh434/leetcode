/*
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。


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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = 0;
        int temp = diameterOfBinaryTreeCore(root, res);
        return res;
    }
    
    int diameterOfBinaryTreeCore(TreeNode* root, int &res){
        if(root == NULL)
            return -1;
        
        
        int left = diameterOfBinaryTreeCore(root->left, res)+1;
        int right = diameterOfBinaryTreeCore(root->right, res)+1;
        // cout<< root->val<<" " << left<<" "  << right<<endl;
        int lr = left+right;
        if(lr > res)
            res = lr;
        
        return max(left,right);
    }
};