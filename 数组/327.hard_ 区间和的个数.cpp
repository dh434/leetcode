/*
给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，
包含 lower 和 upper。

区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，
包含 i 和 j (i ≤ j)。

说明:
最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。

示例:

输入: nums = [-2,5,-1], lower = -2, upper = 2,
输出: 3 
解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。

*/

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> record(nums.size()+1, 0);
        for(int i = 0;i<nums.size();++i)
            record[i+1]=record[i] + nums[i];
        return countRangeSumCore(record, lower, upper, 0 ,record.size());
    }
    
    int countRangeSumCore(vector<long>& nums, int lower, int upper, int left, int right){
        if(right - left <= 1) return 0;
        
        int mid = (right+left) /2;
        int res = countRangeSumCore(nums, lower, upper, left ,mid) + countRangeSumCore(nums, lower, upper, mid ,right);
        int m = mid;
        int n = mid;
        for(int i = left;i<mid;++i){
            while(m < right && nums[m] - nums[i] < lower) m++;
            while(n < right && nums[n] - nums[i] <= upper) n++;
            
            res += (n-m);
        }
        inplace_merge(nums.begin()+left, nums.begin()+mid, nums.begin()+right);
        
        return res;
    }
};