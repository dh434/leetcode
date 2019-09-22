/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

*/

//详情见
//https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/


//至少应该想到dp

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0)
            return 0;
        
        int res = 0;
        int left = 0;
        int mark = 0;
        for (int i = 0; i < s.size(); ++i) {
            int prev_mark = mark;
            mark = max(0, mark + ((s[i] == '(') ? 1 : -1));
            if (mark == 0) {
                if (prev_mark > 0) {
                    res = max(i - left + 1, res);
                } else {
                    left = i + 1;
                }
            }
        }
        mark = 0;
        int right = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            int prev_mark = mark;
            mark = max(0, mark + ((s[i] == ')') ? 1 : -1));
            if (mark == 0) {
                if (prev_mark > 0) {
                    res = max(right - i + 1, res);
                } else {
                    right = i - 1;
                }
            }
        }
        return res;


        
    }
};