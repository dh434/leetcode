/*
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        
        int start = 0;
        while(start*2 < row_num && start*2 <col_num){
            rotateCore(matrix, start);
            ++start;
        }
    }
    
    void rotateCore(vector<vector<int>>& matrix, int start){
        
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        
        int start_x = start;
        int start_y = start;
        int end_x = col_num -1 - start_x;
        int end_y = row_num -1 - start_y;
        
        if(start_x < end_x && start_y < end_y){
            for(int k =0;k<end_x-start_x;++k)
                swapFourPoint(matrix,start_x, start_y,end_x,end_y,k);
        }else if(start_x == end_x && end_y == start_y+1){
            
            int temp = matrix[start_x][start_y];
            matrix[start_x][start_y]= matrix[start_x][end_y];
            matrix[start_x][end_y] = temp;
        }
    }
    
    void swapFourPoint(vector<vector<int>>& matrix,int start_x, int start_y,int end_x, int end_y, int k){
    
        int temp = matrix[start_x][start_y+k];
        matrix[start_x][start_y+k] = matrix[end_x-k][start_y];
        matrix[end_x-k][start_y] = matrix[end_x][end_y-k];
        matrix[end_x][end_y-k] = matrix[start_x+k][end_y];
        matrix[start_x+k][end_y] = temp;
    }
    
};