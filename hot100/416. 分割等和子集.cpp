/*
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.
*/

//还有一个优化版
//0-1背包问题
// 不能拿重复的，每个只能拿一个
// 看能否组成这个数字


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num:nums) sum+= num;
        
        if(sum %2 != 0)
            return false;
        
        int m = sum/2;
        
        vector<vector<bool>> dp(nums.size(), vector<bool>(m+1,false));
        
        if(nums[0] <= m)
            dp[0][nums[0]] = true;
        
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<=m;++j){
                
                dp[i][j] = dp[i-1][j];
                if(nums[i] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];   //不拿和拿
            }
        }
        
        return dp[nums.size()-1][m];
    }
};