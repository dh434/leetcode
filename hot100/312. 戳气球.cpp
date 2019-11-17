        
/*
有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。

求所能获得硬币的最大数量。

说明:

你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
示例:

输入: [3,1,5,8]
输出: 167 
解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
     coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

*/
        
        
// 以最后一个戳爆的气球为中心
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int len = nums.size();
        if(len == 0)
            return 0;
        
        vector<int> a;
        a.push_back(1);
        for(auto num:nums) a.push_back(num);
        a.push_back(1);
        
        vector<vector<int>> dp(len+2, vector<int>(len+2, 0));
        
        for(int l= 3;l<=len+2;++l){
            
            for(int i =0;i<=len+2-l;++i){
                int j = i+l-1;
                dp[i][j] = 0;
                for(int k = i+1;k<j;++k){
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i]*a[k]*a[j]);
                }
            }
        }
        
        return dp[0][len+1];
    }
};      
  //区间型动态规划
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n ==0 ) return 0;
        vector<int> a(nums);
        //因为题意中可以假设nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破
        //所以新建一个vector，在首末加上1
        a.insert(a.begin(),1);
        a.push_back(1);
        //f[i][j]代表在vector<int> a里下标i到j，其中i和j不被扎破，i+1到j-1全被扎破最多获得的金币数
        int i, j ,k, L,f[n+2][n+2];
        
        //初始化f ，因为下标i和i+1不被扎破，并且i和i+1之间没有气球，所以f[i][i+1] = 0
        for( i = 0 ; i < n+1; i++){
            f[i][i+1] = 0;
        }
        //区间型动态规划 按照长度从小到大的顺序遍历！！！！！这样才不会覆盖结果
        //L代表vector<int> a里下标i到j闭区间的长度
        for(L = 3; L <= n+2; L++){
            // i是区间的左端点， j是区间的右端点，
            for(i = 0; i <= n - L + 2;i++ ){
                j = L + i - 1;
                f[i][j] = 0;
                //遍历 所有k的可能，k表示下标i到j闭区间中最后被扎破的气球的下标
                for(k = i+1; k < j; k++){
                    // k是最后被扎破的气球的下标，那么扎破k获得的金币数是a[i]*a[k]*a[j]
                    // 再加上k的左区间f[i][k] 和 右区间 f[k][j]
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i]*a[k]*a[j]);
                }
            }
        }
        //return f[0][n+1]代表在vector<int> a,其中下标0和n+1不被扎破，1到n全被扎破最多获得的金币数
        return f[0][n+1];
    }
};
