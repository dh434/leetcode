/*
满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。

返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。

答案中每个树的每个结点都必须有 node.val=0。

你可以按任何顺序返回树的最终列表。

 

示例：

输入：7
输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
解释：


提示：

1 <= N <= 20
在真实的面试中遇到过这道题？
*/

// 首先要注意满二叉树的定义，确定N的取值限制
// 不要嫌麻烦，想做就去做，要记住中间结果

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
private:
    map<int, vector<TreeNode*>> mp;

public:
    vector<TreeNode*> allPossibleFBT(int N) {
        
        if(mp.find(N) == mp.end()){
            vector<TreeNode*> res;
            
            if(N == 1){
                res.push_back(new TreeNode(0));
                mp[N] = res;
            }else if (N % 2 == 1){
                for(int i =1; i <N;++i){
                    int j = N-1-i;
                    for(auto left: allPossibleFBT(i)){
                        for(auto right : allPossibleFBT(j)){
                            TreeNode* root = new TreeNode(0);
                            root->left = left;
                            root->right = right;
                            res.push_back(root);
                        }
                    }
                    
                }
                mp[N] = res;
            }
        }
        
        return mp[N];
        
    }
};