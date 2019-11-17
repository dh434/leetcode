/*
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

 

示例 ：

输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
 

提示：

给定的数组的大小在 [1, 1000] 之间。

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        
        return constructMaximumBinaryTreeCore(nums,0,nums.size()-1);
    }
    
    TreeNode* constructMaximumBinaryTreeCore(vector<int>& nums,int left, int right){
        if(left > right)
            return nullptr;
        if(left == right)
            return new TreeNode(nums[left]);
        
        
        int max_num = INT_MIN;
        int index = -1;
        for(int i = left; i<=right;++i)
            if(nums[i] > max_num){
                max_num = nums[i];
                index = i;
            }
        
        TreeNode* root = new TreeNode(nums[index]);
        
        root->left = constructMaximumBinaryTreeCore(nums, left, index-1);
        root->right = constructMaximumBinaryTreeCore(nums, index+1,right);
        
        
        return root;
        
    }
};