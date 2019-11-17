/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_num = matrix.size();
        if(row_num == 0)
            return false;
        int col_num = matrix[0].size();
        
        int i = 0;
        int j = col_num -1;
        while(i < row_num && j >=0){
            int num = matrix[i][j];
            if(num < target)
                i++;
            else if(num > target)
                j--;
            else
                return true;
        }
        
        return false;
    }
};