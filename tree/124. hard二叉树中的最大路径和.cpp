/*
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

*/

// 可申明全局变量


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        
        maxPathSumCore(root, INT_MIN, maxSum);
        return maxSum;
    }
    
    int maxPathSumCore(TreeNode* root, int currentSum, int& maxSum) {
        if(root == NULL)
            return 0;
        
        
        int val = root->val;
        if(currentSum < 0){
            currentSum = val;
        }else{
            currentSum += val;
        }
        
        if(currentSum > maxSum)
            maxSum = currentSum;
        
        
        int reverse_sum = val;
        int left=-1, right=-1;
        
        left = maxPathSumCore(root->left, currentSum, maxSum);
        right = maxPathSumCore(root->right, currentSum, maxSum);
        
        left = max(0, left);
        right = max(0,right);
        if(val + left + right > maxSum)
            maxSum = val + left + right;
        
        reverse_sum += (left>right?left:right);
        return reverse_sum;
        
//         if(root->left == NULL && root->right == NULL)
//             return val;
//         if(root->left == NULL || root->right == NULL){
//             reverse_sum += (left == -1?0:left);
//             reverse_sum += (right == -1?0:right);
            
//             if(reverse_sum<val)
//                 reverse_sum = val;
            
//             if(reverse_sum > maxSum)
//                 maxSum = reverse_sum;
            
//             return reverse_sum>0?reverse_sum:(val>0?val:0);
//         }else{
//             if(val + left + right > maxSum)
//                 maxSum = val + left + right;
            
//             if(left <0 && right <0)
//                 return val>0?val:0;
//             else{
//                 reverse_sum += (left>right?left:right);
//                 if(reverse_sum > maxSum)
//                     maxSum = reverse_sum;
//                 return reverse_sum;
//             }
            
            
//         }
        
        
    }
};