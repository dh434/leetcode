/*
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        
        flattenCore(root);
        return;
    }
    
    
    TreeNode* flattenCore(TreeNode* root) {
        if(root == NULL)
            return root;
        
        TreeNode* lastNode = root;
        TreeNode* temp_right = root->right;
        
        if(root->left != NULL){
            root->right = root->left;
            root->left = NULL;
            lastNode = flattenCore(root->right);
        }
        
        if(temp_right != NULL){
            lastNode->right = temp_right;
            lastNode = flattenCore(lastNode->right);
        }
        
        return lastNode;
    }
};