/*
给出二叉树的根节点 root，树上每个节点都有一个不同的值。

如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。

返回森林中的每棵树。你可以按任意顺序组织答案。

示例：

输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
输出：[[1,2,null,4],[6],[7]]
 

提示：

树中的节点数最大为 1000。
每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
to_delete.length <= 1000
to_delete 包含一些从 1 到 1000、各不相同的值。

*/

//注意的是，最后要再判断一下root


class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == NULL)
            return {};
        vector<TreeNode*> res;
        
        TreeNode* new_root = delNodesCore(root, to_delete, res);

        if(new_root){
            res.push_back(root);
        }
        return res;
    }

    TreeNode* delNodesCore(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& res){

        if(root == NULL)
            return NULL;

        int root_val = root->val;
        bool check_in = false;
        for(auto td : to_delete)
            if(root_val == td){
                check_in = true;
                break;
            }
        root->left = delNodesCore(root->left, to_delete, res);
        root->right = delNodesCore(root->right, to_delete, res);
        
        if(check_in){
            if(root->left != NULL)
                res.push_back(root->left);
            if(root->right != NULL)
                res.push_back(root->right);
            
            // delete root;
            return NULL;
        }else{
            return root;
        }


    }
};