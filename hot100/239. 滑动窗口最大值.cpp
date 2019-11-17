/*

给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

 

进阶：

你能在线性时间复杂度内解决此题吗？

*/

//滑动窗口中，比新数小的，不会对后面有影响

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> record;
        
        int len = nums.size();
        vector<int> res;
        if(len < k || len ==0)
            return res;
        
        
        for(int i=0;i<k;++i){
            while(!record.empty() && nums[record.back()] < nums[i])
                record.pop_back();
            record.push_back(i);
        }
        res.push_back(nums[record.front()]);
        
        for(int i = k;i<len;++i){
            
            while(!record.empty() && record.front() <= i-k)
                record.pop_front();
            
            while(!record.empty() && nums[record.back()] < nums[i])
                record.pop_back();
            
            record.push_back(i);
            res.push_back(nums[record.front()]);
        }
        
        return res;
        
    }
};