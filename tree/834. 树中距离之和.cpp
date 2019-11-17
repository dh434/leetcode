
/*
给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1 条边 。

第 i 条边连接节点 edges[i][0] 和 edges[i][1] 。

返回一个表示节点 i 与其他所有节点距离之和的列表 ans。

示例 1:

输入: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
输出: [8,12,6,10,10,10]
解释: 
如下为给定的树的示意图：
  0
 / \
1   2
   /|\
  3 4 5

我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5) 
也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
说明: 1 <= N <= 10000


*/






// 树型dp
// 把树分成两堆，首先要抛弃根节点这个概念
//要推导出数学公式

// http://www.pianshen.com/article/3509184857/


class Solution 
{
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) 
    {
        vector<unordered_set<int>> graph(N);
        vector<int> res(N, 0);
        vector<int> count(N, 1);
        for (auto e : edges)
        {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        dfs1(graph, res, count);
        dfs2(graph, res, count, N);
        return res;
    }
private:
    void dfs1(const vector<unordered_set<int>>& graph, vector<int>& res, vector<int>& count, int node=0, int parent=-1)
    {
        for (int child : graph[node])
        {
            if (child != parent)
            {
                dfs1(graph, res, count, child, node);
                count[node] += count[child];
                res[node] += res[child] + count[child];
            }
        }
    }
    
    void dfs2(const vector<unordered_set<int>>& graph, vector<int>& res, vector<int>& count, int N, int node=0, int parent=-1)
    {
        for (int child : graph[node])
        {
            if (child != parent)
            {
                res[child] = res[node] - 2*count[child] + N;
                dfs2(graph, res, count, N, child, node);
            }
        }
    }
};




