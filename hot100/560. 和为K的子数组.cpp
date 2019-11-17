/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。


*/



//累加和
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        int[] sum = new int[nums.length + 1];
        sum[0] = 0;
        for (int i = 1; i <= nums.length; i++)
            sum[i] = sum[i - 1] + nums[i - 1];
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
    }
}

// 累计和的升级版，思路是不是和map，求减有点类似
// best
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        
        map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int res =0;
        
        for(int i=0;i<len;++i){
            sum += nums[i];
            if(mp.find(sum-k) != mp.end())
                res += mp[sum-k];
            
            mp[sum]++;
        }
        
        return res;
        
    }
};