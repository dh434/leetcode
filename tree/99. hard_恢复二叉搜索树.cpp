/*
二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:

输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]

   3
  /
 1
  \
   2
示例 2:

输入: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

输出: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
进阶:

使用 O(n) 空间复杂度的解法很容易实现。
你能想出一个只使用常数空间的解决方案吗？

这道题难点,是找到那两个交换节点,把它交换过来就行了.

这里我们二叉树搜索树的中序遍历(中序遍历遍历元素是递增的)

如下图所示, 中序遍历顺序是 4,2,3,1,我们只要找到节点4和节点1交换顺序即可!

这里我们有个规律发现这两个节点:

第一个节点,是第一个按照中序遍历时候前一个节点大于后一个节点,我们选取前一个节点,这里指节点4;

第二个节点,是在第一个节点找到之后, 后面出现前一个节点大于后一个节点,我们选择后一个节点,这里指节点1;
*/

// 可以继续使用中序遍历

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
    void recoverTree(TreeNode* root) {
        bool res = true;
        while(res)
            res = findErrorNode(root,NULL,NULL);
    }
    
    
    bool findErrorNode(TreeNode* root, TreeNode* min_node, TreeNode* max_node){
        
        if(root == NULL)
            return false;
        
        long min = LONG_MIN;
        if(min_node != NULL){
            min = min_node->val;
            
            if(root->val <= min){
                min_node->val = root->val;
                root->val = min;
                return true;
            }
        }
        
        bool found = findErrorNode(root->left, min_node, root);
        
        if(found) return true;
        
        long max = LONG_MAX;
        if(max_node != NULL){
            max = max_node->val;
            
            if(root->val >= max){
                max_node->val = root->val;
                root->val = max;
                return true;
            }
        }
        
        
        found = findErrorNode(root->right, root, max_node);    
        
        if(found) return true;
        else return false;
        
    }
};