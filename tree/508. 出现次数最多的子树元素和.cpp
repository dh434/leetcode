/*
给出二叉树的根，找出出现次数最多的子树元素和。一个结点的子树元素和定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。然后求出出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的元素（不限顺序）。

 

示例 1
输入:

  5
 /  \
2   -3
返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。

示例 2
输入:

  5
 /  \
2   -5
返回 [2]，只有 2 出现两次，-5 只出现 1 次。

 

提示： 假设任意子树元素和均可以用 32 位有符号整数表示。

*/


class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        map<int,int> mp;
        
        int sum = postOrder(root, mp);
        
        int maxTime = 0;
        vector<int> res;
        int curTime = -1;
        
        
        for(auto it : mp){
            if(maxTime == 0){
                maxTime = it.second;
                res.push_back(it.first);
            }else{
                
                if(it.second > maxTime){
                    res.clear();
                    res.push_back(it.first);
                    maxTime = it.second;
                }else if(it.second == maxTime)
                    res.push_back(it.first);
            }
        }
        
        return res;
        
    }
    
    int postOrder(TreeNode* root, map<int,int>& res){
        
        if(root==NULL)
            return 0;
        if(root->left == NULL && root->right == NULL){
            res[root->val] ++;
            return root->val;
        }
        
        int left = postOrder(root->left, res);
        int right = postOrder(root->right, res);
        
        
        int sum = root->val + left + right;
        res[sum] ++;
        
        return sum;
    }
};