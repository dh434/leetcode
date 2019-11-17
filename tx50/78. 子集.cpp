/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

//回溯的思想

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        
        int len = nums.size();
        
        for(int i=0;i<len;++i){
            int temp_len = res.size();
            for(int j=0;j<temp_len;++j){
                vector<int> temp= res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        
        return res;
        
        
    }
};