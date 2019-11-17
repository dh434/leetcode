/*
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

输入: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]
说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:

你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。

*/

// 使用前缀树来剪枝
// 反过来想，先把target字符串加入树中，然后再遍历过程中，判断是否继续。


class TrieNode
{
public:
    TrieNode()
    {
        data = vector<TrieNode*>(26, nullptr);
        isWord=false;
    }
    vector<TrieNode*> data;
    bool isWord;
};

//Trie的板子，基本上撸出这个板子后面就容易多了。这套板子也非常容易理解。
class Trie
{
  public:
    TrieNode* root;
    
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string s)
    {
        TrieNode* temp = root;
        for(int i=0;i<s.size();++i)
        {
            if(temp->data[s[i]-'a'] == nullptr)
            {
                temp->data[s[i]-'a']=new TrieNode();
            }
            temp = temp->data[s[i]-'a'];
        }
        temp->isWord = true;
    }
    
    bool search(string s)
    {
        TrieNode* temp = root;
        for(int i=0;i<s.size();++i)
        {
            if(temp->data[s[i]-'a'] == nullptr)
            {
                return false;
            }
            temp = temp->data[s[i]-'a'];
        }
        return  temp->isWord;
    }
    
    bool ispre(string s)
    {
        TrieNode* temp = root;
        for(int i=0;i<s.size();++i)
        {
            if(temp->data[s[i]-'a'] == nullptr)
            {
                return false;
            }
            temp = temp->data[s[i]-'a'];
        }
        return true;
    }
    
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string a : words)
        {
            trie.insert(a);
        }
        unordered_set<string> res;
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), true));
        //对于board当中的每一个字符都进行遍历，来得到最终的结果。
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[i].size();++j)
            {
                vis = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), true));
                string cur = "";
                cur+= board[i][j];
                vis[i][j]=false;
                DFS(board, trie, vis, res, cur, i, j);
                vis[i][j]=true;
            }
        }
        
        vector<string> ret;
        for(string x : res)
        {
            ret.push_back(x);
        }
        
        return ret;
    }
    
    void DFS(vector<vector<char>>& board, Trie& trie,  vector<vector<bool>>& vis, unordered_set<string>& res, string cur, int x, int y)
    {
        //完成查询，将目标插入结果
        if(trie.search(cur))
        {
            res.insert(cur);
        }
        
        //如果当前字符串不是前缀，那么就直接返回，不用继续DFS了，因为找不到了。
        if(!trie.ispre(cur))
        {
            return;
        }
        
        //下面是四个方向的标准深度搜索
            if(x-1>=0&&vis[x-1][y])
            {
                vis[x-1][y]=false;
                cur += board[x-1][y];
                DFS(board, trie, vis, res, cur, x-1, y);
                cur = cur.substr(0, cur.size()-1);
                vis[x-1][y]=true;   
            }
            if(y-1>=0&&vis[x][y-1])
            {
                vis[x][y-1]=false;
                cur += board[x][y-1];
                DFS(board, trie, vis, res, cur, x, y-1);
                cur = cur.substr(0, cur.size()-1);
                vis[x][y-1]=true;   
            }
            if(x+1<board.size()&&vis[x+1][y])
            {
                vis[x+1][y]=false;
                cur += board[x+1][y];
                DFS(board, trie, vis, res, cur, x+1, y);
                cur = cur.substr(0, cur.size()-1);
                vis[x+1][y]=true;   
            }
            if(y+1<board[0].size()&&vis[x][y+1])
            {
                vis[x][y+1]=false;
                cur += board[x][y+1];
                DFS(board, trie, vis, res, cur, x, y+1);
                cur = cur.substr(0, cur.size()-1);
                vis[x][y+1]=true;   
            }
        
    }
    
};

