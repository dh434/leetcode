/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

*/

// 感觉考得是逻辑
// dp，从小的数字开始，需要遍历的候选数据，用set保存

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        map<int, set<vector<int>> > record;
                
        for(int i = 1;i<=target;++i){
            for(auto c : candidates){
                
                if(i == c)
                    record[i].insert({c});
                else if( c < i){
                    for(auto it : record[i-c]){
                        it.push_back(c);
                        sort(it.begin(), it.end());
                        record[i].insert(it);
                    }
                }
            }
        }
        
        vector<vector<int>> ret;
        for(auto it : record[target])
            ret.push_back(it);
        
        return ret;
        
    
        
    }
};