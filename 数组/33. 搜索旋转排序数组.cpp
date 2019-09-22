/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

*/
//排序数组中，二分的思想还蛮常见
//很关键的一个想法是，究竟分割点在哪一边，若在右边，则左边是连续向上的，
//这样想的话，就很很容易想明白
//还有就是 边界情况还是要注意一下，数组类：数组的长度是特别要关注的

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int left = 0, right = nums.size()-1;
        if(nums.size() == 0)
            return -1;
        
        return searchCore(nums, target, 0, nums.size()-1);
    }
    
    
    int searchCore(vector<int>& nums, int target, int left, int right){

        int mid = (left+right)/2;
        // cout<< left << " "<<mid<<" " << right<<endl;
        if(left == right){
            if(nums[left] == target) return left;
            else return -1;
        }

        
        if(nums[mid] >= nums[left]){
            if(target >= nums[left] && target <= nums[mid])
                return searchCore(nums, target, left, mid);
            else
                return searchCore(nums, target, mid+1, right);
        }
        else{
            if(target < nums[mid] || target > nums[right])
                return searchCore(nums, target, left, mid-1);
            else
                return searchCore(nums, target, mid, right);
        }  
    }
};