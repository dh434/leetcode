/*
给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false

*/

//注意审题，利用桶排序的思想

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        if(len == 0 || len == 1 || t < 0)
            return false;
        
        unordered_map<long , long > record;
        long a = t;
        long w = a + 1;
        for(int i =0 ;i<len;++i){
            int pos = getID(nums[i], w);
            if(record.find(pos) != record.end()) return true;
            
            if(record.find(pos-1) != record.end() && abs(nums[i] - record[pos-1]) <= t) return true;
            
            if(record.find(pos+1) != record.end() && abs(nums[i] - record[pos+1]) <= t) return true;
            
            record[pos] = nums[i];
            if(i>=k)
                record.erase(getID(nums[i-k], w));
        }
        
        return false;
        
        
    }
    
    long getID(long x, long w) {
        return x < 0 ? ((x + 1) / w )- 1 : x / w;
    }

};