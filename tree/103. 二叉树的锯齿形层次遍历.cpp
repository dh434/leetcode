/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

*/

// 使用两个stack


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        stack<TreeNode*> m_stack[2];
        m_stack[0].push(root);
        int current = 0;
        int next = 1;
        
        vector<int> temp_list;
        
        while(!m_stack[0].empty() || !m_stack[1].empty()){
            TreeNode* pNode = m_stack[current].top();
            m_stack[current].pop();
            
            if(current == 0){
                if(pNode->left != NULL) m_stack[next].push(pNode->left);
                if(pNode->right != NULL) m_stack[next].push(pNode->right);
            }else{
                if(pNode->right != NULL) m_stack[next].push(pNode->right);
                if(pNode->left != NULL) m_stack[next].push(pNode->left);
            }
            
            temp_list.push_back(pNode->val);
            
            if(m_stack[current].empty()){
                vector<int> pVector(temp_list);
                res.push_back(pVector);
                
                current = 1-current;
                next = 1-next;
                temp_list.clear();
            }
            
        }
        
        return res;
    }
};