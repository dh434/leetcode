/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

*/

// 递规的DFS

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int row_num = board.size();
        if(row_num == 0)
            return ;
        
        int col_num = board[0].size();
        if(col_num == 0)
            return ;
        
        vector<vector<bool>> free(row_num, vector<bool>(col_num, false));
        
        vector<int> out_row = {0, row_num-1};
        vector<int> out_col = {0, col_num-1};
        for(int i =0;i<2;++i){
            for(int j=0;j<col_num;++j){
                int row = out_row[i];
                int col = j;
                
                if(!free[row][col] && board[row][col] == 'O')
                    freeFriend(board, free, row, col);
            }
        }
        
        for(int i =0;i<row_num;++i){
            for(int j=0;j<2;++j){
                int row = i;
                int col = out_col[j];
                
                if(!free[row][col] && board[row][col] == 'O')
                    freeFriend(board, free, row, col);
            }
        }
        
        for(int i =1;i<row_num-1;++i){
            for(int j=1;j<col_num-1;++j){
                
                if(!free[i][j] && board[i][j] == 'O')
                    board[i][j]='X';
            }
        }
        
        
    }
    
    
    void freeFriend(vector<vector<char>>& board, vector<vector<bool>>& free, int row, int col){
        // cout<< row << " " << col <<endl;
        free[row][col] = true;
        
        if(row - 1 >=0 && board[row - 1][col] == 'O' && !free[row - 1][col])
            freeFriend(board, free, row- 1, col);
        if(row + 1 < board.size() && board[row + 1][col] == 'O' && !free[row + 1][col])
            freeFriend(board, free, row + 1, col);
        
        if(col + 1 < board[0].size() && board[row][col+1] == 'O' && !free[row][col+1])
            freeFriend(board, free, row , col+ 1);
        if(col - 1 >=0 && board[row][col-1] == 'O' && !free[row][col-1])
            freeFriend(board, free, row, col-1);
    }
};