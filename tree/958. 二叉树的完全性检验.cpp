/*
给定一个二叉树，确定它是否是一个完全二叉树。

百度百科中对完全二叉树的定义如下：

若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：第 h 层可能包含 1~ 2h 个节点。）

 

示例 1：

输入：[1,2,3,4,5,6]
输出：true
解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3} 的两层），且最后一层中的所有结点（{4,5,6}）都尽可能地向左。

*/

//best
// 层次遍历二叉树
// 将二叉树的结点依照层次序列（广度优先搜索序列）依次放入队列。
// 当一个结点的左子结点为空时，若其右子结点不为空或其后的结点存在子结点，则不为完全二叉树；
// 当一个结点的右子结点为空时，若其后的结点存在子结点，则不为完全二叉树。反之，则为完全二叉树。


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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL)
            return true;
        
        queue<TreeNode*> mq;
        
        mq.push(root);
        bool hasNullptr = false;
        while(!mq.empty()){
            int len = mq.size();
            
            for(int i=0;i<len;++i){
                TreeNode* temp = mq.front();
                mq.pop();
                if(temp == NULL) 
                    hasNullptr = true;
                else{
                    if(hasNullptr)
                        return false;
                    
                    mq.push(temp->left);
                    mq.push(temp->right);
                }
            } 
        }
        
        return true;
    }
};