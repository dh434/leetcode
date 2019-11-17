/*
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3

*/

// 广度遍历

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0)
            return 0;
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),false));
        int res = 0;
        for(int i = 0;i<grid.size();++i){
            for(int j =0;j<grid[0].size();++j){
                
                if(grid[i][j] == '1' && visited[i][j] == false){
                    res++;
                    findlands(grid, visited, i, j);
                }
                
            }
        }
        
        return res;
        
    }
    
    
    void findlands(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
        
        if(row<0 || row >= grid.size() || col <0 || col >= grid[0].size() || grid[row][col] != '1' || visited[row][col])
            return;
        
        visited[row][col] = true;
        
        findlands(grid, visited, row+1, col);
        findlands(grid, visited, row-1, col);
        findlands(grid, visited, row, col+1);
        findlands(grid, visited, row, col-1);
        
    }
};