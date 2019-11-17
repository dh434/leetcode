/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> record(nums.size());
        int res = 0;
        
        for(int i =nums.size()-1;i>=0;--i){
            
            int temp = 0;
            
            for(int j = i+1;j<nums.size();++j){
                if(nums[j] > nums[i])
                    temp = max(temp, record[j]);
            }
            
            record[i] = temp + 1;
            res = max(res, record[i]);
        }
        
        return res;
    }
};

//best

/*
很具小巧思。新建数组 cell，用于保存最长上升子序列。

对原序列进行遍历，将每位元素二分插入 cell 中。

如果 cell 中元素都比它小，将它插到最后
否则，用它覆盖掉比它大的元素中最小的那个。
总之，思想就是让 cell 中存储比较小的元素。这样，cell 未必是真实的最长上升子序列，但长度是对的。

*/

// Dynamic programming + Dichotomy.
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] tails = new int[nums.length];
        int res = 0;
        for(int num : nums) {
            int i = 0, j = res;
            while(i < j) {
                int m = (i + j) / 2;
                if(tails[m] < num) i = m + 1;
                else j = m;
            }
            tails[i] = num;
            if(res == j) res++;
        }
        return res;
    }
}
