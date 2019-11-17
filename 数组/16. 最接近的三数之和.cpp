/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_gap = INT_MAX;
        int res = 0;
        int len = nums.size();
        
        for(int i = 0;i<=len-3;++i){
            int j = len-1;
            int k = i+1;
            
            while(k < j){
                int sum = nums[i] + nums[k] + nums[j];
                if(sum == target)
                    return target;
                else if(sum < target)
                    k++;
                else
                    j--;
                
                if(abs(sum-target) < min_gap){
                    min_gap = abs(sum-target);
                    res = sum;
                }
            }
            
            // if(res > target)
            //     break;
        }
        
        return res;
        
    }
};