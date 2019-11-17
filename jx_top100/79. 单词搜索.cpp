/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

*/

//必须先找出第一个单词的位置
//然后深度优先搜索

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int row_num = board.size();
        int col_num = board[0].size();
        
        vector<vector<char>> visited(row_num, vector<char>(col_num, false));
        
        for(int i =0;i<row_num;++i){
            for(int j = 0;j<col_num;++j){
                if(board[i][j] == word[0] && dfs(visited, board, word, i,j,0))
                    return true;
            }
        }
        
        return false;
        
    }
    
    bool dfs(vector<vector<char>> &visited, vector<vector<char>>& board, string word,int row, int col, int wIndex){
        
        if(wIndex == word.size())
            return true;
        
        if(row <0 || row >= board.size() || col <0 || col >= board[row].size() || visited[row][col])
            return false;
        
        if(!visited[row][col] && board[row][col] == word[wIndex]){
            visited[row][col] = true;
            
            bool m1 = dfs(visited, board, word, row-1,col,wIndex+1);
            if(m1) return m1;
            
            bool m2 = dfs(visited, board, word, row+1,col,wIndex+1);
            if(m2) return m2;
            
            bool m3 = dfs(visited, board, word, row,col+1,wIndex+1);
            if(m3) return m3;
            
            bool m4 = dfs(visited, board, word, row,col-1,wIndex+1);
            if(m4) return m4;
            visited[row][col] = false;
        }
        
        return false;
        
    }
    
    
    
    
};