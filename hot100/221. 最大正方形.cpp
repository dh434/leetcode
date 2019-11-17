/*
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4

*/

/*
我们用 0 初始化另一个矩阵 dp，维数和原始矩阵维数相同；
dp(i,j) 表示的是由 1 组成的最大正方形的边长；
从 (0,0)(0,0) 开始，对原始矩阵中的每一个 1，我们将当前元素的值更新为
dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
我们还用一个变量记录当前出现的最大边长，这样遍历一次，
找到最大的正方形边长 maxsqlenmaxsqlen，那么结果就是 maxsqlen^2maxsqlen 
2
 。

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0)
            return 0;
        int col = matrix[0].size();
        
        vector<vector<int>> dp(row+1, vector<int>(col+1,0));
        
        int max_len = 0;
        
        for(int i =1;i<=row;++i){
            for(int j = 1;j<=col;++j){
                
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    max_len = max(max_len, dp[i][j]);
                }
                
            }
        }
        
        return max_len * max_len;
    }
};