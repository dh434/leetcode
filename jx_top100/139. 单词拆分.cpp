/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int len = s.size();
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for(int i = 0;i<len;++i){
            
            int cur_len = i+1;
            for(auto word:wordDict){
                int word_len = word.size();
                if(cur_len == word_len || (cur_len > word_len && dp[cur_len - word_len])){
                    
                    string sub_word = s.substr(i - word_len + 1, word_len);
                    if(sub_word == word){
                        dp[cur_len] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[len];
        
    }
};

//另一种
// 我们用下标 i 来考虑所有从当前字符串开始的可能的子字符串。对于每一个子字符串，我们通过下标 j 将它拆分成 s1's1 
//   和 s2's2 
//   （注意 i 现在指向 s2's2 
//   的结尾）。为了将 dp[i] 数组求出来，我们依次检查每个 dp[j] 是否为 true ，也就是子字符串 s1's1 
//   是否满足题目要求。如果满足，我们接下来检查 s2's2 
//   是否在字典中。如果包含，我们接下来检查 s2's2 
//   是否在字典中，如果两个字符串都满足要求，我们让 \text{dp}[i]dp[i] 为 \text{true}true ，否则令其为 \text{false}false 。

public class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> wordDictSet=new HashSet(wordDict);
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordDictSet.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
}
