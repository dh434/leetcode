/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return false;
        
        unordered_map<char,int> char_table;
        
        for(auto c:s){
            if(char_table.count(c)!=0)
                char_table[c] = char_table[c]+1;
            else
                char_table[c] = 1;
        }
        
        for(auto c:t){
            if(char_table.count(c)!=0){
                
                if(char_table[c] == 0)
                    return false;
                else
                    char_table[c] =  char_table[c]-1;
            }
                
            else
                return false;
        }
        
        for (auto it = char_table.begin(); it != char_table.end(); ++it )
            if(it->second != 0)
                return false;
        
        return true;
    }
};