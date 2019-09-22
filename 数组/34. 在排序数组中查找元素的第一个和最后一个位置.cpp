/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

*/

// 基础问题是在排序数组中查找target，用二分， log（N)
// 这道题则是需要找到区间，转化为找第一个和最后一个的问题

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1,-1};
        if(nums.size() == 0)
            return res;
        
        int first = getFirstK(nums,target, 0, nums.size()-1);
        if(first == -1)
            return res;
        else
            res[0] = first;
        int second = getLastK(nums, target, 0, nums.size()-1);
        res[1] = second;
        return res;
    }
    
    
    int getFirstK(vector<int> nums, int target, int left, int right){
        if(left > right)
            return -1;
        
        
        int mid = (left + right) /2;
        int midData = nums[mid];
        
        if(midData == target){
            if(mid == 0 || (mid > 0 && nums[mid-1] != target))
                return mid;
            else
                right = mid - 1;
        }
        else if(midData > target){
            right = mid-1;
        }else
            left = mid+1;
        
        return getFirstK(nums, target, left, right);
    }
    
    int getLastK(vector<int> nums, int target, int left, int right){
        if(left > right)
            return -1;
        
        
        int mid = (left + right) /2;
        int midData = nums[mid];
        int len = nums.size();
        
        if(midData == target){
            if(mid == len-1 || (mid < len-1 && nums[mid+1] != target))
                return mid;
            else
                left = mid + 1;
        }
        else if(midData > target){
            right = mid-1;
        }else
            left = mid+1;
        return getLastK(nums, target, left, right);
    }
};