/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

// 回溯

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> a{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        if(digits.empty())
            return result;
        result.push_back("");
        for(auto num:digits){
            int index = num - '2';
            int len = result.size();
            
            for(int i =0 ;i<len;++i){
                for(auto m:a[index]){
                    result.push_back(result[i] + m);
                }
            }
            
            result.erase(result.begin(), result.begin()+len);
        }
        
        return result;
    }
};