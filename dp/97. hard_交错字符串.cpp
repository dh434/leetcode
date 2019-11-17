/*
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false

*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1_len = s1.size();
        int s2_len = s2.size();
        int s3_len = s3.size();
        
        if(s1_len + s2_len < s3_len)
            return false;
        
        if(s1_len == 0){
            return s2 == s3;
        }
        if(s2_len == 0){
            return s1 == s3;
        }
        
        vector<vector<bool>> matrix(s1_len+1, vector<bool>(s2_len+1));
        
        for(int i =0;i<=s1_len;++i){
            for(int j =0;j<=s2_len;++j){
                if(i==0 && j==0){
                    matrix[i][j] = true;
                }else if(i == 0){
                    matrix[i][j] = matrix[i][j-1] && (s2[j-1] == s3[i+j-1]);
                }else if(j == 0){
                    matrix[i][j] = matrix[i-1][j] && (s1[i-1] == s3[i+j-1]);
                }else{
                    matrix[i][j] = (matrix[i][j-1] &&  (s2[j-1] == s3[i+j-1]) ) ||
                                   (matrix[i-1][j] && (s1[i-1] == s3[i+j-1]));
                }
            }
        }
        
        return matrix[s1_len][s2_len];
    }
};