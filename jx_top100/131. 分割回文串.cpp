/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

//这道题典型的 不是只有dp，要坚持自己一开始的想法，
// 既然想到dp，就继续想下去，然后呢，还得用回溯解决

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        
        int s_len = s.size();
        vector<vector<bool>> dp(s_len, vector<bool>(s_len,false));
        
        for(int len =1;len<= s_len;++len){
            for(int i=0;i <= s_len-len;++i){
                int j = i+len-1;
                dp[i][j] = ((s[i] == s[j]) &&( len < 3 || dp[i+1][j-1]));
            }
        }
        vector<string> temp;
        partitionHelper(s,0, dp,temp,res);
        
        return res;
    }
    
    void partitionHelper(string s, int start, vector<vector<bool>> dp, vector<string>& temp, vector<vector<string>>& res){
        if(start == s.size()){
            res.push_back(temp);
            return ;
        }
        
        for(int i = start;i<s.size();++i){
            if(dp[start][i]){
                string left = s.substr(start, i-start+1);
                temp.push_back(left);
                partitionHelper(s,i+1, dp,temp,res);
                temp.pop_back();
            }
        }
    }
    
    
};