/*
给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

示例 1:

输入: nums = [1, 5, 1, 1, 6, 4]
输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
示例 2:

输入: nums = [1, 3, 2, 2, 3, 1]
输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
说明:
你可以假设所有输入都会得到有效的结果。

进阶:
你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？

*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        int mid = (len+1) / 2;
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        
        int i = mid -1;
        int j = len -1;
        for(int index =0;index<len;++index){
            // cout<<i << " " << j<<endl;
            nums[index] = index%2 == 0?tmp[i--]:tmp[j--];
        }
    
    }
};