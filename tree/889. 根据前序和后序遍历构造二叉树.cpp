/*
返回与给定的前序和后序遍历匹配的任何二叉树。

 pre 和 post 遍历中的值是不同的正整数。

7
1 5 7
5
1 3 5
3
1 1 3
1 1 1
1 1 2
1 1 3 2
1 3 1
1 3 2
1 3 3
1 3 4
1 3 5 4
1 5 1
1 5 2
1 5 3
1 5 4
1 5 5
1 5 6
1 5 7
1 5 8
1 5 7 8
3 3 7
3
1 1 3
1 1 1
1 1 2
1 1 3 2
3
1 1 3
1 1 1
1 1 2
1 1 3 2
3 3 1
3 3 2
3 3 3
3 3 4
3 3 5
3 3 6
3 3 7
3 3 8
3 3 7 8

示例：

输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
输出：[1,2,3,4,5,6,7]
 

提示：

1 <= pre.length == post.length <= 30
pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。

*/

//注意是前序和后序，不是前序和中序

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return constructFromPrePostCore(pre, post, 0, pre.size()-1, 0, post.size()-1);
    }
    
    TreeNode* constructFromPrePostCore(vector<int>& pre, vector<int>& post,
                                  int pre_left, int pre_right,
                                  int post_left, int post_right) {
        
        if(pre_left > pre_right || post_left > post_right)
            return nullptr;
        
        int root_val = pre[pre_left];
        
        TreeNode* root = new TreeNode(root_val);
        
        if(pre_left == pre_right)
            return root;
        
        int left_val = pre[pre_left+1];
        
            
        int post_index = post_left;
        for(; post_index <= post_right;++post_index)
            if(post[post_index] == left_val)
                break;
        
        int left_len = post_index - post_left + 1;
        int right_len = post_right - post_index - 1;
        
        if(left_len > 0)
            root->left = constructFromPrePostCore(pre, post, pre_left+1, pre_left+left_len, post_left, post_index);
        
        if(right_len > 0)
            root->right = constructFromPrePostCore(pre, post, pre_left+left_len+1, pre_right,post_index+1, post_right-1);
        return root;
    }
};