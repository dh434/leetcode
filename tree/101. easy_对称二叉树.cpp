/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
*/


//注意queue的使用  push, pop, front, back()

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> nodes;
        
        if(root == NULL)
            return true;
        
        nodes.push(root->left);
        nodes.push(root->right);
        while(!nodes.empty()){
            TreeNode* node1 = nodes.front();
            nodes.pop();
            TreeNode* node2 = nodes.front();
            nodes.pop();
            if(node1 == NULL && node2 == NULL) continue;
            if(node1 == NULL || node2 == NULL) return false;
            cout<<node1->val << " " << node2->val<<endl;

            if(node1->val != node2->val) return false;
            
            nodes.push(node1->left);
            nodes.push(node2->right);
            
            nodes.push(node1->right);
            nodes.push(node2->left);
        }
        
        return true;
    }
};