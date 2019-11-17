/*
给定一个树，按中序遍历重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。

 

示例 ：

输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

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
            \
             7
              \
               8
                \
                 9  
 

提示：

给定树中的结点数介于 1 和 100 之间。
每个结点都有一个从 0 到 1000 范围内的唯一整数值。

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

//学会去设置class， 设置私有变量，记录更多的状态，方便自己的思考和写代码

class Solution {
private:
    TreeNode* pre;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL)
            return root;
        
        TreeNode* cur = new TreeNode(0);
        pre = cur;
        inorder(root);
        return cur->right;
    }
    
    
    void inorder(TreeNode* root ){
        
        if(root == NULL)
            return;
        
        inorder(root->left);
        root->left = NULL;
        pre->right = root;
        pre = root;
        inorder(root->right);
    }
};