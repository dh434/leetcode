/*
在一个 m*n 的二维字符串数组中输出二叉树，并遵守以下规则：

行数 m 应当等于给定二叉树的高度。
列数 n 应当总是奇数。
根节点的值（以字符串格式给出）应当放在可放置的第一行正中间。根节点所在的行与列会将剩余空间划分为两部分（左下部分和右下部分）。你应该将左子树输出在左下部分，右子树输出在右下部分。左下和右下部分应当有相同的大小。即使一个子树为空而另一个非空，你不需要为空的子树输出任何东西，但仍需要为另一个子树留出足够的空间。然而，如果两个子树都为空则不需要为它们留出任何空间。
每个未使用的空间应包含一个空的字符串""。
使用相同的规则输出子树。
示例 1:

输入:
     1
    /
   2
输出:
[["", "1", ""],
 ["2", "", ""]]
示例 2:

输入:
     1
    / \
   2   3
    \
     4
输出:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
示例 3:

输入:
      1
     / \
    2   5
   / 
  3 
 / 
4 
输出:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
注意: 二叉树的高度在范围 [1, 10] 中。

*/

// 注意保存状态

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        
        if(root == NULL)
            return {{}};
        
        int depth = getDepth(root);
        
        int width = 0;
        
        for(int i =0;i<depth;++i)
            width += pow(2,i);
        
        vector<vector<string>> res(depth, vector<string>(width,""));
        

        
        fillMatrix(res, 1, 0, 0, width-1, root, depth, width);
        
        return res;
    }
    
    int getDepth(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(getDepth(root->left), getDepth(root->right))+1;
    }
    
    
    void fillMatrix(vector<vector<string>> &res, int curDepth, int curRow,
                    int left,int right,
                    TreeNode* root, int depth, int width){
        if(root == NULL || curRow < 0 || curRow >= depth || left>right)
            return ;
        
        int curCol = (left+right)/2;
        
        res[curRow][curCol] = to_string(root->val);
        
        int gap = depth - curDepth;
        
        fillMatrix(res, curDepth+1, curRow+1, left,curCol-1, root->left, depth, width);
        
        fillMatrix(res, curDepth+1, curRow+1, curCol+1,right, root->right, depth, width);
        
        
    }
    
    
};