/*
给定二叉树的根节点 root，找出存在于不同节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。

（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）

 

示例：



输入：[8,3,10,1,6,null,14,null,null,4,7,13]
输出：7
解释： 
我们有大量的节点与其祖先的差值，其中一些如下：
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
 

提示：

树中的节点数在 2 到 5000 之间。
每个节点的值介于 0 到 100000 之间。

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
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL)
            return 0;
        int max_val = root->val;
        int min_val = root->val;
        int res = 0;


        maxAncestorDiffCore(root->left,max_val  , min_val, res);
        maxAncestorDiffCore(root->right, max_val, min_val, res);

        return res;
    }

    void maxAncestorDiffCore(TreeNode* root, int max_val, int min_val, int& res){
        if(root == NULL)
            return ;


        res = max(res, abs(root->val - max_val));
        res = max(res, abs(root->val - min_val));

        max_val = max(max_val, root->val);
        min_val = min(min_val, root->val);
        maxAncestorDiffCore(root->left, max_val, min_val, res);
        maxAncestorDiffCore(root->right, max_val, min_val, res);
        return ;

    }
};