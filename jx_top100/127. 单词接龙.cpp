/*
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。

*/

//超时
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        bool hasEndWord = false;
        for (auto word : wordList)
            if(word == endWord) {hasEndWord = true; break;}
        
        if(!hasEndWord)
            return 0;
        
        int res = ladderLengthCore(beginWord, endWord, 0, wordList);
        return res==INT_MAX?0:res;
        
    }
    
    int ladderLengthCore(string beginWord, string endWord,int path_length, vector<string>& wordList){
        
        if(beginWord == endWord)
            return path_length+1;
        
        
        int min_length = INT_MAX;
        
        for(int i=0;i<wordList.size();++i){
            if(isChangeWord(beginWord, wordList[i])){
                // cout<<beginWord<<" "<< wordList[i]<<endl;
                string targetWord = wordList[i];
                wordList.erase(wordList.begin()+i);
                int temp = ladderLengthCore(targetWord, endWord, path_length+1, wordList);
                wordList.insert(wordList.begin()+i, targetWord);
                if(temp < min_length)
                    min_length = temp;
            }
        }
        
        return min_length;
        
    }
    
    
    bool isChangeWord(string a, string b){
        int index_a = 0;
        int index_b = 0;
        int count = 0;
        
        while(index_a < a.size()){
            if(a[index_a++] == b[index_b++])
                count ++;
        }
        
        if(count == a.size() - 1)
            return true;
        else
            return false;
        
    }
};

// BFS
// 应该想到用queue
// 从beginword出发，遍历其变种的可能性，若在集合中且不在已有路径中，放入queue和路径中
// 宽度遍历，有点层序遍历的味道
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) {
            return 0;
        }
        unordered_map<string, int> pathCnt = {{beginWord, 1}};
        queue<string> q{{beginWord}};
        while(!q.empty()){
            string word = q.front();
            q.pop();
            for(int i =0;i<word.size();++i){
                for(auto ch = 'a';ch<='z';++ch){
                    string newWord = word;
                    newWord[i] = ch;
                    
                    if(wordSet.count(newWord)!=0 && newWord == endWord)
                        return pathCnt[word] + 1;
                    
                    if(wordSet.count(newWord)!=0 && !pathCnt.count(newWord)){
                        pathCnt[newWord] = pathCnt[word] + 1;
                         q.push(newWord);
                    }
                }
            }
        }
        return 0;  
    }
};

//双向BFS