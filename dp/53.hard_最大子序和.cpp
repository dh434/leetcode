/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int nums_len = nums.size();
        int max_sum = nums[0];
        int current_sum = nums[0];
        
        for(int i = 1;i<nums_len;++i){
            if(current_sum < 0){
                current_sum = nums[i];
            }else{
                current_sum += nums[i];
            }
            
            if(current_sum > max_sum)
                max_sum = current_sum;
        }
        
        return max_sum;
        
    }
};