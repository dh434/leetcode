/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

*/

// vector  resverse


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root == NULL)
            return res;
        
        queue<TreeNode*> m_queue;
        m_queue.push(root);
        
        while(!m_queue.empty()){
            int len = m_queue.size();
            
            vector<int> temp_list;
            
            for(int i = 0;i<len;++i){
                TreeNode* pNode = m_queue.front();
                m_queue.pop();
                
                temp_list.push_back(pNode->val);
                
                if(pNode->left!=NULL) m_queue.push(pNode->left);
                if(pNode->right!=NULL) m_queue.push(pNode->right);
            }
            
            res.push_back(temp_list);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};