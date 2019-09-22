/*
给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。

示例 1:

输入:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

输出: 
"apple"
示例 2:

输入:
s = "abpcplea", d = ["a","b","c"]

输出: 
"a"
说明:

所有输入的字符串只包含小写字母。
字典的大小不会超过 1000。
所有输入的字符串长度不会超过 1000。

*/

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        
        string res = "";
        
        for(auto sub:d){
            int i = 0;
            int j = 0;
            while(j < sub.size() && i <s.size()){
                if(sub[j] == s[i]){
                    ++i;
                    ++j;
                }else{
                    ++i;
                }
            }
            if(j == sub.size())
                if(sub.size() > res.size() || (sub.size() == res.size() && sub < res))
                    res = sub;
            
        }
        return res;
        
    }
};