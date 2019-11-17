/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
注意:

数组非空，且长度不会超过20。
初始的数组的和不会超过1000。
保证返回的最终结果能被32位整数存下。

*/

// 注意有0的情况
// 学会转化为0-1背包问题

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        
        int sum = 0;
        for(auto n:nums) sum +=n;
        if(sum < S) return 0;
        
        
        if((sum+S)%2!=0 ) return 0;
        
        int target = (sum+S)/2;
        
        
        //special case:
        int nZeros=0;
        for(auto it=nums.begin();it!=nums.end();){
            if(*it==0){
                nZeros++;
                it=nums.erase(it);
            }else ++it;
        }

        if(nums.size() == 0)
            return 1<<nZeros;

        
        vector<vector<int>> dp(nums.size(), vector<int>(target+1,0));
        
        if(nums[0] <= target)
            dp[0][nums[0]] = 1;
        
        for(int i=0;i<nums.size();++i)
            dp[i][0] = 1;
        
        for(int i = 1;i<nums.size();++i){
            for(int j= 0;j<=target;++j){
                
                dp[i][j] = dp[i-1][j];
                if(nums[i] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
            }
        }
        
        return dp[nums.size()-1][target]*(1<<nZeros);;
        
    }
};