/*
给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

以 10^9 + 7 为模，返回这些数字之和。

 

示例：



输入：[1,0,1,0,1,0,1]
输出：22
解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

提示：

树中的结点数介于 1 和 1000 之间。
node.val 为 0 或 1 。
在真实的面试中遇到过这道题？

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
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL)
            return 0;
        int sum = 0;
        int num = 0;
        dfs(root, sum, num);
        return sum;
        
    }

    void dfs(TreeNode* root,int &sum, int num){
        if(root == NULL)
            return ;
        
        int val = num << 1 | root->val;

        if(root->left == NULL && root->right == NULL)
            sum += val;
        
        dfs(root->left, sum, val);
        dfs(root->right, sum, val);
        return ;
    }

   

};