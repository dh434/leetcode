/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

*/

// dp之余，要学会去优化空间，原地修改


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if(triangle.empty())
            return 0;
        
        int row = triangle.size();
        for(int i = row-2;i>=0;--i){
            for(int j=i;j>=0;--j){
                triangle[i][j] += min(triangle[i+1][j] , triangle[i+1][j+1]);
            }
        }
        
        return triangle[0][0];
        
    }
};