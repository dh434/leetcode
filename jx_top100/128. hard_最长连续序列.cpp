/*
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

*/

// 首先得总结出若以一个数字开始，则它的n-1不应该在nums里出现

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> record;
        for(auto num :nums)
            record[num] = 1;
        
        
        int max_len = 0;
        for(auto num:nums){
            
            if(record.find(num-1) == record.end()){
                int cur_len = 1;
                int cur_num = num+1;
                while(record.find(cur_num)!= record.end()){
                    cur_len++;
                    cur_num++;
                }
                
                if(cur_len > max_len)
                    max_len = cur_len;
            }
        }
        
        return max_len;
        
    }
};