/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1

*/

//一道dp的题目，假设我们知道 F(S)F(S) ，
// 对于金额 SS 最少的硬币数，最后一枚硬币的面值是 CC。
// 那么由于问题的最优子结构以下方程应为：F(S)=F(S−C)+1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int len = coins.size();
        
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=1;i<=amount;++i){
            for(int j = 0;j<len;++j){
                if(i >= coins[j]){
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        // cout<<dp[amount]<<endl;
        return dp[amount] >amount?-1:dp[amount];
        
            
    }
};