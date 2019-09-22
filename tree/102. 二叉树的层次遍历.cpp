/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodes;
        
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        nodes.push(root);
        while(!nodes.empty()){
            int m_size = nodes.size();
            vector<int> temp_list;
            
            for(int i =0;i<m_size;++i){
                
                TreeNode* temp_node = nodes.front();
                nodes.pop();
                
                temp_list.push_back(temp_node->val);
                
                if(temp_node->left!=NULL) nodes.push(temp_node->left);
                if(temp_node->right!=NULL) nodes.push(temp_node->right);
            }
            res.push_back(temp_list);
            
        }
        
        return res;
    }
};