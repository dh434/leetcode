/*
给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

案例 1:

输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

输出: True
 

案例 2:

输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

输出: False
 
*/

//中序遍历+双指针

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
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)
            return false;
        
        
        vector<int> treeVal;
        inOrder(root,treeVal);
        
        int len = treeVal.size();
        int left = 0;
        int right = len - 1;
        
        while(left < right){
            int sum = treeVal[left] + treeVal[right];
            if(sum < k) left++;
            else if(sum > k) right --;
            else return true;
        }
        
        return false;
        
    }
    
    
    void inOrder(TreeNode* root,vector<int> &treeVal){
        
        stack<TreeNode*> st;
        TreeNode* cur = root;
        
        while(cur!=NULL || !st.empty()){
            
            while(cur!=NULL){
                st.push(cur);
                cur = cur->left;
            }
            
            cur = st.top();
            treeVal.push_back(cur->val);
            st.pop();
            
            cur = cur->right;
            
        }
        return ;
        
    }
};