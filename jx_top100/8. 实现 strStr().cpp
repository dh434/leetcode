/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

*/
//KMP O(M+N)

// 再看看题解 https://leetcode-cn.com/problems/implement-strstr/solution/c5chong-jie-fa-ku-han-shu-bfkmpbmsunday-by-2227/

class Solution {
private:
    
public:
    int strStr(string haystack, string needle) {
        
        int N = haystack.size();
        int M = needle.size();
        if(M == 0 )
            return 0;
        
        if(N == 0 )
            return -1;
        
        vector<vector<int> > dp(M, vector<int>(256,0));
        kmp(needle,dp);
        int j =0;
        for(int i =0;i<N;++i){
            j = dp[j][haystack[i]];
            if(j == M)
                return i-M+1;
        }
        
        return -1;
        
    }
    
    void kmp(string needle,vector<vector<int> > &dp){
        int M = needle.size();
        
        dp[0][needle[0]] = 1;
        
        int X = 0;
        for(int j=1;j<M;++j){
            for(int c=0;c<256;++c){
                if (needle[j] == (char)c) 
                    dp[j][c] = j + 1;
                else 
                    dp[j][c] = dp[X][c];

            }
            
            X = dp[X][needle[j]];
        }
    }
};