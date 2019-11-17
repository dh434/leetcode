/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0)
            return res;
        
        permutation(nums, 0, res);
        return res;
    }
    
    void permutation(vector<int>& nums, int begin, vector<vector<int>>& res){
        if(begin == nums.size()){
            vector<int> temp(nums);
            res.push_back(temp);
        }else{
            for(int i = begin; i<nums.size();++i){
                swap(nums, i, begin);
                permutation(nums,begin+1, res);
                swap(nums,begin,i);
            }
        }
    }
    
    void swap(vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};