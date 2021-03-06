/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        int depth = 0;
        return isBalanced(root,depth);
    }
    
    bool isBalanced(TreeNode* root, int& depth) {
        
        if(root == NULL){
            depth = 0;
            return true;
        }
        
        int left = 0;
        bool balance = isBalanced(root->left, left);
        if(!balance)
            return false;
        
        int right = 0;
        balance = isBalanced(root->right, right);
        if(!balance)
            return false;
        
        
        depth = max(left, right) + 1;
        
        return abs(left-right) <= 1;
    }
};