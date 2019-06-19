/*
105. 从前序与中序遍历序列构造二叉树

根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

 */

/*
emmm,好久没做c++了
1. size需要加括号
2. 还是会有变量写错的bug，导致调试很久
3. 
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
#include<iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          if (preorder.size() == 0 && inorder.size() == 0){
            return NULL;
        }
        
        return constructTree(preorder, inorder, 0, preorder.size() -1, 0, inorder.size() -1 );
    }
    
     TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,int p_start,int p_end,int i_start,int i_end ){
        
         // cout<<p_start<<p_end<<i_start<<i_end<<endl;
         
        int rootval = preorder[p_start];
        TreeNode* root = new TreeNode(rootval);
        
        if (p_start == p_end){
            if(i_start == i_end && preorder[p_start] == inorder[i_start]){
                return root;
            } 
            else
            {
                return NULL;
            }
        }

        int root_inorder_index = i_start;
        
        while(root_inorder_index <= i_end && inorder[root_inorder_index] != rootval){
                ++ root_inorder_index;
        }

        if (root_inorder_index == i_end && inorder[root_inorder_index]!= rootval){
            return NULL;
        }
        int leftLength = root_inorder_index - i_start;
        int left_preorder_end = p_start + leftLength;
        if (leftLength > 0){
            root->left = constructTree(preorder, inorder, p_start + 1, left_preorder_end, i_start, root_inorder_index -1);
        }
        if(leftLength < p_end - p_start){
            root->right = constructTree(preorder, inorder, left_preorder_end+1, p_end, root_inorder_index +1 , i_end);
        }

        return root;

    }
};
