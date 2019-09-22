/*
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

*/

// 并不需要保存n个结果，只保存中间两个就可以


class Solution {
public:
    
    bool ValidNumber(char l, char r) {
        int value = (l - '0') * 10 + r - '0';
        return l > '0' && value >= 1 && value <= 26;
    }
    
    bool ValidNumber(char c) {
        return c >= '1' && c <= '9';
    }


    int numDecodings(string s) {
        int s_len = s.size();
        if(s_len == 0) return 0;
        if(s[0] == '0') return 0;
        if(s_len == 1) return 1;
        
        int dp0 = 1;
        int dp1 = 1;
        for(int i =1;i<s_len;++i){
            int dp = 0;
            if (ValidNumber(s[i])) {
                dp += dp1;
            }
            if (ValidNumber(s[i - 1], s[i])) {
                dp += dp0;
            }
            dp0 = dp1;
            dp1 = dp;

        }
        
        return dp1;
    }
};