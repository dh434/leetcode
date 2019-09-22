/*
给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

若可行，输出任意可行的结果。若不可行，返回空字符串。

示例 1:

输入: S = "aab"
输出: "aba"
示例 2:

输入: S = "aaab"
输出: ""
注意:

S 只包含小写字母并且长度在[1, 500]区间内。

*/

class Solution {
public:
    string reorganizeString(string S) {
        int len = S.size();
        vector<int> record(26, 0);
        
        int max_num = 0;
        for(auto c:S){
            record[c-'a'] ++;
            max_num = max(max_num, record[c-'a']);
        }
        
        if(max_num > (len+1)/2)
            return "";
        
        char res[len+1];
        int even = 0, odd = 1;
        for(int i =0;i<26;++i){ 
             while(record[i] > 0 && odd < len  && record[i]<(len/2+1)){
                res[odd] = i+'a';
                record[i]--;
                odd += 2;
            }
            
            while(record[i] > 0 && even < len){
                res[even] = i+'a';
                record[i]--;
                even += 2;
            }
            
           
        }
        res[len] = '\0';
        string res_str = res;
        
        return res_str;
            
        
    }
};