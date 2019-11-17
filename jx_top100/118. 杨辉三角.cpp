/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;
        res.push_back({1});
        if(numRows == 1) return res;
        res.push_back({1,1});
        if(numRows == 2) return res;
        
        for(int i = 2;i<numRows;++i){
            vector<int> temp;
            temp.push_back(1);
            // cout<<1<<endl;
            int pre_len = res[i-1].size();
            // cout<<i<<endl;
            for(int j = 0;j<=pre_len-2;++j){
                temp.push_back(res[i-1][j] + res[i-1][j+1]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        
        return res;
        
    }
};