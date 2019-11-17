/*
给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。

二叉搜索树保证具有唯一的值。

 

示例 1：

输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
输出：32
示例 2：

输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
输出：23
 

提示：

树中的结点数量最多为 10000 个。
最终的答案保证小于 2^31。

*/

// 都为闭区间

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL)
            return 0;
        
        int root_val = root->val;
        
        int sum = 0;
        if(root->val >= L && root->val <= R)
            sum += root_val;
        
        if(root_val >= L) sum += rangeSumBST(root->left, L, R);
        if(root_val <= R ) sum += rangeSumBST(root->right, L, R);
        
        return sum;
            
    }
};