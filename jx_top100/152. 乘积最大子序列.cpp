/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

*/

//一定要多举例

//超时
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        int res = nums[0];
        int nums_size = nums.size();
        vector<vector<int>> dp(nums_size, vector<int>(nums_size));
        
        for(int len = 1; len<=nums_size;++len){
            for(int i = 0;i<=nums_size-len;++i){
                int j = i+len-1;
                dp[i][j] = nums[i];
                if(i+1 <= j)
                    dp[i][j] *= dp[i+1][j];
                
                res = max(res, dp[i][j]);
            }
        }
        
        return res;
        
        
    }
};

//best O(n)

class Solution {
    public int maxProduct(int[] nums) {
        int max = Integer.MIN_VALUE, imax = 1, imin = 1;
        for(int i=0; i<nums.length; i++){
            if(nums[i] < 0){ 
              int tmp = imax;
              imax = imin;
              imin = tmp;
            }
            imax = Math.max(imax*nums[i], nums[i]);
            imin = Math.min(imin*nums[i], nums[i]);
            
            max = Math.max(max, imax);
        }
        return max;
    }
}

int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i, ret, pos, neg, temp;
        pos = nums[0];
        neg = nums[0];
        ret = nums[0];
        for(i = 1; i < nums.size(); i++){
            temp = pos;
            pos = max(nums[i], max(pos * nums[i], neg * nums[i]));
            neg = min(nums[i], min(temp * nums[i], neg * nums[i]));
            ret = max(pos, ret);
        }
        return ret;
    }


// 令imax为当前最大值，则当前最大值为 
// imax = max(imax * nums[i], nums[i])
// 由于存在负数，那么会导致最大的变最小的，最小的变最大的。
// 因此还需要维护当前最小值imin，imin = min(imin * nums[i], nums[i])
// 当负数出现时则imax与imin进行交换再进行下一步计算
// 时间复杂度：O(n)
