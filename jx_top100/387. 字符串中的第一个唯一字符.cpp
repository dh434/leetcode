/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 

注意事项：您可以假定该字符串只包含小写字母。
=
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        
        
        map<char,int> mp;
        
        for(int i=0;i<s.size();++i){
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = i;
            else
                mp[s[i]] = -1;
        }
        
        
        int min_index = INT_MAX;
        for(auto item :mp){
            if(item.second >=0 && item.second < min_index)
                min_index = item.second;
        }
        
        return min_index == INT_MAX?-1:min_index;
    }
};