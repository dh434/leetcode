/*
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
示例 1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2:

输入: word1 = "intention", word2 = "execution"
输出: 5
解释: 
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_len = word1.size();
        int word2_len = word2.size();
        
        if(word1_len == 0)
            return word2_len;
        if(word2_len == 0)
            return word1_len;
        
        vector<vector<int>> matrix(word1_len+1, vector<int>(word2_len+1));
        
        for(int i = 0;i<=word2_len;++i) matrix[0][i] = i;
        for(int i =0;i<=word1_len;++i) matrix[i][0] = i;
        
        
        for(int i = 1;i<word1_len+1;++i){
            for(int j =1; j<word2_len+1;++j){
                
                int d = 1;
                if(word1[i-1] == word2[j-1])
                    d = 0;
                
                matrix[i][j] = min(matrix[i-1][j-1]+d, min(matrix[i][j-1]+1, matrix[i-1][j]+1));
            }
        }
        
        return matrix[word1_len][word2_len];
    }
    
    // int min3(int x, int y, int z) {
    //     return min(min(x, y), z);
    // }
    // int minDistance(string word1, string word2) {
    //     int R = word1.size();
    //     int C = word2.size();
    //     int dp[R + 1][C + 1] = {0};
    //     for (int i = 0; i <= R; ++i) dp[i][0] = i;
    //     for (int i = 0; i <= C; ++i) dp[0][i] = i;
    //     for (int i = 1; i <= R; ++i) {
    //         for (int j = 1; j <= C; ++j) {
    //             dp[i][j] = min3(
    //                 dp[i - 1][j] + 1, 
    //                 dp[i][j - 1] + 1, 
    //                 dp[i - 1][j - 1] + int(word1[i - 1] != word2[j - 1]));
    //         }
    //     }
    //     return dp[R][C];
    // }


};