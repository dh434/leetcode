/*
给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）


*/
// 本来开始想的是遍历一次求所有位置的左积，再遍历一次求所有位置的右积，再遍历一次求左积*右积
// 然后看了大家的题解，发现一个o(n)的，原作者在这里
// 思路大概是用双指针标记每个位置的左积(left)和右积(right)，这样在一次遍历中就可以计算出结果。
// eg:[1,2,3,4,5]
// 2的左积在i=1时就算出，并且会更新此时的左积值。而其右积则在i=3时算出。
// 56ms 90.99%


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int left = 1,right=1;
        vector<int> res(len,1);
        for(int i=0;i<len;++i){
            res[i] *= left;
            left *= nums[i];
            
            res[len-1-i] *= right;
            right*=nums[len-1-i];
        }
        
        return res;
    }
};