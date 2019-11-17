/*
给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

例如, 

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和 插入的值: 5
你可以返回这个二叉搜索树:

         4
       /   \
      2     7
     / \   /
    1   3 5
或者这个树也是有效的:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4

*/

/**
1如果二叉搜索树为空树，用val构造二叉树节点作为根节点并返回。
2否则，搜索新结点的插入位置，沿子结点关系向下：
遇到应该走向左子树而左子树为空，或者应该走向右子树而右子树为空时，就是找到了新字典项的插入位置，构造新结点并完成实际插入。
之后，返回根节点。

 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
            return root;
        
        if(root->val < val){
            if(root->right == NULL){
                root->right = new TreeNode(val);
            }else
                root->right = insertIntoBST(root->right,val);
        }else{
            if(root->left == NULL){
                root->left = new TreeNode(val);
            }else
                root->left = insertIntoBST(root->left,val);
        }
        return root;
    }
};