/*
给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。

每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。

示例 1:

输入: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

输出: 4
解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
示例 2:

输入: 

          1
         /  
        3    
       / \       
      5   3     

输出: 2
解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
示例 3:

输入: 

          1
         / \
        3   2 
       /        
      5      

输出: 2
解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
示例 4:

输入: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
输出: 8
解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
注意: 答案在32位有符号整数的表示范围内。

*/

//层序+序号
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode*, long>> mq;
        mq.push(make_pair(root, 1));
        long max_width = 0;
        while(!mq.empty()){
            
            int len = mq.size();
            int start_pos = mq.front().second;
            int end_pos = start_pos;
            for(int i = 0;i<len;++i){
                TreeNode* temp = mq.front().first;
                end_pos = mq.front().second;
                mq.pop();
                
                if(temp->left !=NULL) mq.push(make_pair(temp->left, (long)end_pos*2-1));
                if(temp->right !=NULL) mq.push(make_pair(temp->right, (long)end_pos*2));
                
            }
            if(end_pos- start_pos + 1 > max_width)
                max_width = end_pos- start_pos + 1;
            // max_width = max(max_width, end_pos- start_pos + 1);
            
        }
        
        return (int)max_width;
    }
};