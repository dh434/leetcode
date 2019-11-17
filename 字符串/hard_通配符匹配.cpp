/*
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
示例 3:

输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
示例 4:

输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
示例 5:

输入:
s = "acdcb"
p = "a*c?b"
输入: false

*/

//保存最后一个* ， 回溯

class Solution {
public:
    bool isMatch(string s, string p) {
        
        
        int s_len = s.size();
        int p_len = p.size();
        int s_index = 0;
        int p_index = 0;
        
        int star_flag = -1;
        int match = -1;
        
        while(s_index < s_len){
            if(p_index < p_len && (s[s_index] == p[p_index] || p[p_index] == '?')){
                s_index ++;
                p_index ++;
            }else if(p_index < p_len && p[p_index] == '*'){
                star_flag = p_index;
                p_index ++;
                match = s_index;
            }else if(star_flag != -1){
                p_index = star_flag + 1;
                match++;
                s_index = match;
            }else
                return false;
            
        }
        
        while(p_index < p_len && p[p_index] == '*')
            p_index ++;
        
        return p_index == p_len;
        
    }
};