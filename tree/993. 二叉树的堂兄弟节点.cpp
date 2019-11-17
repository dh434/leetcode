/*
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。

如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。

我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。

只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。

 

示例 1：


输入：root = [1,2,3,4], x = 4, y = 3
输出：false
示例 2：


输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
输出：true
示例 3：



输入：root = [1,2,3,null,4], x = 2, y = 3
输出：false
 

提示：

二叉树的节点数介于 2 到 100 之间。
每个节点的值都是唯一的、范围为 1 到 100 的整数。

*/



class Solution {
private:
    bool res = false;
    bool firstPoint = false;
    int deep = 0;
    TreeNode* parent = NULL;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, 0, NULL);
        return res;
    }

    void dfs(TreeNode* root, int x, int y, int cur_deep,TreeNode* cur_parent ){
        if(root == NULL)
            return ;

        int root_val = root->val;
        if(root_val == x || root_val == y){
            if(!firstPoint){
                firstPoint = true;
                deep = cur_deep;
                parent = cur_parent;
                return ;
            }else{
                if(cur_deep == deep && parent != cur_parent)
                    res = true;
                
                return ;
            }
        }

        if(firstPoint && cur_deep > deep)
            return ;

        dfs(root->left, x, y, cur_deep+1, root);
        dfs(root->right, x, y, cur_deep+1, root);

    }
};