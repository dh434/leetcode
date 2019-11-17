/*

给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。

*/

// 明白一点是：只关心1-n的数字
// 因此可以先查找是否有1
// 对<1 和>n的数字，填1
// 利用数组本身完成标记操作。使得对应位为负数



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        int count  = 0;
        for(auto num : nums)
            if(num == 1){
                count = 1;
                break;
            }
        
        if(count == 0)
            return 1;
        
        if(n == 1)
            return 2;
        
        for(auto &num : nums){
            if(num <= 0 || num > n)
                num = 1;
        }
        
        for(int i = 0;i<n;++i){
            int tar = abs(nums[i]);
            
            if(tar == n)
                nums[0] = -abs(nums[0]);
            else
                nums[tar] = -abs(nums[tar]);
        }
        
        for(int i = 1;i<n;++i)
            if(nums[i] > 0)
                return i;
        
        if(nums[0] > 0)
            return n;
        
        return n+1;
        
    }
};