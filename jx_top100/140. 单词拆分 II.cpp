/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]
示例 2：

输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。
示例 3：

输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]

*/

// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
// ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
//超时

// 相当于每个位置保留着可能的字符床组合，回溯法

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len+1, false);
        vector<vector<string> > res(len+1, vector<string>(1,""));
        dp[0] = true;
        res[0] = {""};
        
        
        map<string,bool> mp;
        for(auto a:wordDict)
            mp[a] = true;
        
        for(int i = 0;i<len;++i){
            vector<string> temp_res;
            int cur_len = i+1;
            for(auto word:wordDict){
                int word_len = word.size();
                if(cur_len == word_len || (cur_len > word_len && dp[cur_len - word_len])){
                    
                    string sub_word = s.substr(i - word_len + 1, word_len);
                    if(mp[sub_word]){
                        // cout<<sub_word<<endl;
                        dp[cur_len] = true;
                        for(auto str:res[cur_len - word_len])
                            temp_res.push_back(str + (str==""?"":" ") + sub_word);
                        
                    }
                }
               
            }
            // cout<<temp_res.size()<<endl;
            res[cur_len] = temp_res;
            
        }
        
        return res[len];
    }
};


// 备忘录回溯

class Solution {
public:
vector<string> wordBreak(string s, vector<string> &wordDict) {

    unordered_set<string> t(wordDict.begin(), wordDict.end());
    unordered_map<int, vector<string>> m;

    return wordBreak2II_bt(s, t, m, 0);
}

vector<string> wordBreak2II_bt(string s, unordered_set<string> &t, unordered_map<int, vector<string>> &m, int index) {

    if (m.count(index)) {
        return m[index];
    }
    vector<string> ret;
    if (index == s.size()) {
        ret.emplace_back("");
    } else
        for (int i = index + 1; i <= s.size(); ++i) {

            if (t.count(s.substr(index, i - index))) {
                vector<string> tmp = wordBreak2II_bt(s, t, m, i);
                for (auto &j : tmp) {
                    ret.push_back(s.substr(index, i - index) + (j.empty() ? "" : " ") + j);
                }
            }
        }
    m[index] = ret;
    return ret;
}

};
