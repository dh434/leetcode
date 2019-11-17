/*
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        
        
        if(root->val != key){
            if(root->left) root->left = deleteNode(root->left, key);
            
            if(root->right) root->right = deleteNode(root->right, key);
            return root;
        }else{
            
            if(root->left == NULL) 
                root = root->right;
            else{
                root->val = root->left->val;
                
                TreeNode* pre_right = root->right;
                TreeNode* left_right = root->left->right;
                TreeNode* left_left = root->left->left;
                
                root->left = left_left;
                
                
                root->right = left_right;
                
                if(pre_right!=NULL){
                    TreeNode* cur = root;
                    while(cur->right!=NULL)
                        cur = cur->right;
                    cur->right = pre_right;
                }

                // if(root-left!=null)
                // root->right = deleteNode(root->right, root->val);
            }
            
            return root;
        }
    }
    
    
    
};