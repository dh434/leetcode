/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


*/



// 滑动窗口
// unordered_set<char>, find(),end(), erase() 的用法


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        
        unordered_set<char> s_set;
        int maxLen = 0;
        int left = 0;
        
        for(int i=0;i<s.size();++i){
            while(s_set.find(s[i]) != s_set.end()){
                s_set.erase(s[left]);
                left ++;
            }
            s_set.insert(s[i]);
            maxLen = max(maxLen, i-left+1);
        }
        
        return maxLen;
        
    }
};