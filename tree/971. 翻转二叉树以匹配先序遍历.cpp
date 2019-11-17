/*
给定一个有 N 个节点的二叉树，每个节点都有一个不同于其他节点且处于 {1, ..., N} 中的值。

通过交换节点的左子节点和右子节点，可以翻转该二叉树中的节点。

考虑从根节点开始的先序遍历报告的 N 值序列。将这一 N 值序列称为树的行程。

（回想一下，节点的先序遍历意味着我们报告当前节点的值，然后先序遍历左子节点，再先序遍历右子节点。）

我们的目标是翻转最少的树中节点，以便树的行程与给定的行程 voyage 相匹配。 

如果可以，则返回翻转的所有节点的值的列表。你可以按任何顺序返回答案。

如果不能，则返回列表 [-1]。

 

示例 1：



输入：root = [1,2], voyage = [2,1]
输出：[-1]
示例 2：



输入：root = [1,2,3], voyage = [1,3,2]
输出：[1]
示例 3：



输入：root = [1,2,3], voyage = [1,2,3]
输出：[]
 

提示：

1 <= N <= 100

*/

//my
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        if(root == NULL){
            if(voyage.size() == 0) return {};
            else return {-1};
        }

        bool match = flipMatchVoyageCore(root, voyage, 0, voyage.size()-1, res);
        if(match == true)
            return res;
        else
            return  {-1};
    }

    bool flipMatchVoyageCore(TreeNode* root, vector<int>& voyage, int start, int end, vector<int>& res){
        if(start > end)
            return false;

        if(root == NULL){
            if(start <= end) return false;
            else return true;
        }

        int root_val = root->val;
        if(root_val != voyage[start])
            return false;

        if(start == end){
            if(root->left == NULL && root->right == NULL) return true;
            else return false;
        }


        if(root->left != NULL){
            int left_val = root->left->val;
            if(left_val == voyage[start+1]){
                if(root->right == NULL)
                    return flipMatchVoyageCore(root->left, voyage, start+1, end, res);
                else{
                    int right_index = -1;
                    int right_val = root->right->val;
                    for(int i = start;i<=end;++i)
                    if(voyage[i] == right_val){
                        right_index = i;
                        break;
                    }
                    if(right_index == -1) return false;

                    return flipMatchVoyageCore(root->left, voyage, start+1, right_index-1, res) &&
                           flipMatchVoyageCore(root->right, voyage, right_index,end, res);

                }
            }else{
                int left_index = -1;
                for(int i = start;i<=end;++i)
                    if(voyage[i] == left_val){
                        left_index = i;
                        break;
                    }
                if(left_index == -1) return false;

                res.push_back(root->val);
                return flipMatchVoyageCore(root->left, voyage, left_index, end, res) &&
                       flipMatchVoyageCore(root->right, voyage, start+1,left_index-1, res);
            }
        }else{
            return flipMatchVoyageCore(root->right, voyage, start+1, end, res);
        }

        return true;

    }
};

//更清晰
//best
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& voyage, int l, int r, bool& valid, vector<int>& res) {
        if (!valid || root == NULL || l > r) return;
        if (root->val != voyage[l]) {
            valid = false;
            return;
        }
        if (root->left == NULL || root->right == NULL) {
            auto child = root->right ? root->right : root->left;
            dfs(child, voyage, l + 1, r, valid, res);
            return;
        }
        int vl = root->left->val;
        int vr = root->right->val;
        int il = -1;
        int ir = -1;
        for (int i = l; i <= r; ++i) {
            if (voyage[i] == vl) il = i;
            if (voyage[i] == vr) ir = i;
        }
        if (il == -1 || ir == -1) {
            valid = false;
            return;
        }
        if (il > ir) {
            res.push_back(root->val);
            dfs(root->left, voyage, il, r, valid, res);
            dfs(root->right, voyage, l + 1, il - 1, valid, res);
        } else {
            dfs(root->left, voyage, l + 1, ir - 1, valid, res);
            dfs(root->right, voyage, ir, r, valid, res);
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        bool valid = true;
        dfs(root, voyage, 0, voyage.size() - 1, valid, res);
        if (valid) return res;
        return {-1};
    }
};