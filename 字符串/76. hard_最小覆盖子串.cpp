/*
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

*/

// 滑动窗口

string s, t;
// 在 s 中寻找 t 的「最小覆盖子串」
int left = 0, right = 0;
string res = s;

while(right < s.size()) {
    window.add(s[right]);
    right++;
    // 如果符合要求，移动 left 缩小窗口
    while (window 符合要求) {
        // 如果这个窗口的子串更短，则更新 res
        res = minLen(res, window);
        window.remove(s[left]);
        left++;
    }
}
return res;




class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        
        int s_len = s.size();
        int t_len = t.size();
        
        unordered_map<char, int> mymap;
        for(auto a:t)
            mymap[a]++;
        
        int t_char_len = mymap.size();

        int target_len = 0;
        int min_len = s_len + 1;
        unordered_map<char, int> windows_map;
        int left = 0;
        int right = 0;
        
        
        while(right < s_len){
            
            char temp_char = s[right];
            
            if(mymap.find(temp_char) != mymap.end()){
                windows_map[temp_char] ++;
            
                if(windows_map[temp_char] == mymap[temp_char])
                    target_len++;
                while(target_len == t_char_len){
                    if(right - left + 1 < min_len){
                        min_len = right - left + 1;
                        res = s.substr(left, min_len);
                    }
                    
                    if(mymap.find(s[left]) != mymap.end()) {
                        windows_map[s[left]] --;
                        if(windows_map[s[left]] < mymap[s[left]]) target_len--;
                    }
                    
                    left++;
                }
            }
            right++;  
            
        }
        
        return res;
        
    }
};