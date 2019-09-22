/*
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6

*/

//满二叉树的性质，如何找层数，如何确定节点个数，二分法

class Solution {
public:
    int countNodes(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int left = countLevel(root->left);
        int right = countLevel(root->right);
        
        if(left == right){
            return (1<<left) + countNodes(root->right);
        }else{
            return (1<<right) + countNodes(root->left);
        }
        
    }
    
    int countLevel(TreeNode* root){
        int level = 0;
        while(root != NULL){
            level ++;
            root = root->left;
        }
        return level;
    }
};
