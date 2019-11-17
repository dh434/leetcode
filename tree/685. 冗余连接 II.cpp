/*
在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。每一个节点只有一个父节点，除了根节点没有父节点。

输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u, v]，用以表示有向图中连接顶点 u and v和顶点的边，其中父节点u是子节点v的一个父节点。

返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。

示例 1:

输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的有向图如下:
  1
 / \
v   v
2-->3
示例 2:

输入: [[1,2], [2,3], [3,4], [4,1], [1,5]]
输出: [4,1]
解释: 给定的有向图如下:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
注意:

二维数组大小的在3到1000范围内。
二维数组中的每个整数在1到N之间，其中 N 是二维数组的大小。

*/

// 先解决入度为2的点，再解决入度为1的

class Solution {
public:
    
    int n;
    vector<int> fa;
    
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size();
        
        if(n == 0)
            return {};
        
        fa.resize(n+1);
        
        vector<int> in_degree(n+1);
        int k = -1;
        for(auto e : edges){
            in_degree[e[1]]++;
        }
        
        for(int i = n-1;i>=0;--i){
            if(in_degree[edges[i][1]] == 2 && ufs(edges, i))
                return edges[i];
        }
        
       
        return ufs_v1(edges);
      
    }
    
    bool ufs(vector<vector<int>>& edges, int except){
        
        for(int i = 1;i<=n;++i)
            fa[i] = i;
        
        for(int i = 0;i<n;++i){
            
            if(i == except)
                continue;
            
            vector<int> e = edges[i];
            
            int x = e[0];
            int y = e[1];
            
            int fx = find(x);
            int fy = find(y);
            if(fx == fy)
                return false;
            else
                fa[fx] = fy;
        }
        return true;
        
    }
    
    vector<int> ufs_v1(vector<vector<int>>& edges){
        
        for(int i = 1;i<=n;++i)
            fa[i] = i;
        
        for(int i = 0;i<n;++i){
            
            vector<int> e = edges[i];
            
            int x = e[0];
            int y = e[1];
            
            int fx = find(x);
            int fy = find(y);
            if(fx == fy)
                return {x,y};
            else
                fa[fx] = fy;
        }
        return {};
        
    }
};