/*
给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

 

示例 1：

输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：

输入：
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
输出：[]
*/


/*
把握前提：
1. 所有单词的长度一样
2. 串联所有单词，所以不需要遍历所有的s

思路：
滑动窗口，每次取固定长度的target字符串

要学会巧妙利用数据结构
hash表，dict

unordered_map<string,int>

*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int s_len = s.size();
        int word_num = words.size();
        if(word_num == 0 || s_len == 0)
            return res;
        
        int word_len = words[0].size();
        if(word_len*word_num > s_len)
            return res;
        
        
        unordered_map<string,int> words_count;
        for(auto word : words)
            words_count[word] ++;

        
        for(int i =0 ;(i+word_len*word_num -1) < s_len;++i){
            // string targer_s = s.substr(i,word_len*word_num);
            unordered_map<string,int> temp_map;
            int j = 0;
            for(j=i;j<i+word_len*word_num;j=j+word_len){
                string target = s.substr(j,word_len);
                
                if(words_count[target]==0){
                    break;
                }else{
                    temp_map[target] ++;
                    if(words_count[target] < temp_map[target])
                        break;
                }
            }

            if(j == (i+word_len*word_num)){
                res.push_back(i);
            }
            
        }
            
        
        return res;
    }
};