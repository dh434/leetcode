/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        vector<int> res;
        if(row == 0 )
            return res;
        int col = matrix[0].size();
        
        int start = 0;
        
        while(start*2 < row && start*2 < col)
          getMatrixCircle(matrix,col,row,start++,res);
        
        return res;
    }
    
    void getMatrixCircle(vector<vector<int>>& matrix, int col, int row, int start,vector<int> &res){
        
        int start_x = start;
        int start_y = start;
        int end_x = col-1-start;
        int end_y = row-1-start;
        //左到右
        for(int i = start;i<=end_x;++i)
            res.push_back(matrix[start][i]);
        //xia
        if(end_y > start_y){
            for(int i = start+1;i<=end_y;++i)
                res.push_back(matrix[i][end_x]);
        }
        //右到左
        if(end_x > start_x && end_y > start_y){
            for(int i = end_x-1;i>=start;--i)
                res.push_back(matrix[end_y][i]);
        }
        //shang
        if(end_y-start_y >=2 && end_x > start_x){
            for(int i = end_y-1;i>start_y;--i)
                res.push_back(matrix[i][start]);
        }
        
    }
};