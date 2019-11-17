/*
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例 1:

输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".
示例 2:

输入: "aaa"
输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
注意:

输入的字符串长度不会超过1000。

*/

class Solution {
public:
    int countSubstrings(string s) {
        int s_len = s.size();
        int res = 0;
        if(s_len == 0)
            return res;
        
        vector<vector<bool>> dp(s_len,vector<bool>(s_len,false));
        
        for(int len = 1;len<=s_len;++len){
            for(int i =0;i<=s_len-len;++i){
                
                int j = i+len-1;
                if(len==1 || (len ==2 && s[i] == s[j]) || (len > 2 && dp[i+1][j-1] && s[i] == s[j] )){
                    res +=1;
                    dp[i][j] = true;
                }
                    
            }  
        }
        
        
        return res;
    }
};