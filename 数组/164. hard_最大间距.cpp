/*
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

示例 1:

输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
示例 2:

输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
说明:

你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。

*/

// 基数排序
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.empty() || nums.size() < 2)
            return 0;
        
        
        int exp = 1;
        int base = 10;
        
        int max_num = *max_element(nums.begin(),nums.end());
        vector<int> aux(nums.size());
        
        while(max_num / exp > 0){
            
            vector<int> count(base, 0);
            
            for(int i =0;i<nums.size();++i)
                count[(nums[i]/exp)%10]++;
            
            for(int i=1;i<count.size();++i)
                count[i] += count[i-1];
            
            for(int i = nums.size() -1 ;i>=0;--i)
                aux[--count[(nums[i]/exp)%10]] = nums[i];
            
            for(int i =0;i<nums.size();++i){

                nums[i] = aux[i];
            }
            exp*=10;
        }
        
        int max_gap = 0;
        for(int i =0;i<nums.size()-1;++i)
            max_gap = max(max_gap, nums[i+1] - nums[i]);
        
        return max_gap;
        
    }
};

//桶排序
class Bucket {
public:
    bool used = false;
    int minval = numeric_limits<int>::max();        // same as INT_MAX
    int maxval = numeric_limits<int>::min();        // same as INT_MIN
};



class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.empty() || nums.size() < 2)
            return 0;
       
        int min_num = *min_element(nums.begin(),nums.end());
        int max_num = *max_element(nums.begin(),nums.end());
        int length = nums.size();
        
        int bucket_size = max(1, (max_num - min_num) / (length - 1));
        int bucket_num = (max_num - min_num) / bucket_size + 1;
        
        vector<Bucket> buckets(bucket_num);
        
        for(int i =0; i<length;++i){
            int bucket_index = (nums[i] - min_num) / bucket_size;
            buckets[bucket_index].used = true;
            buckets[bucket_index].minval = min(buckets[bucket_index].minval, nums[i]);
            buckets[bucket_index].maxval = max(buckets[bucket_index].maxval, nums[i]);
        }
        
        int preBucketMax = min_num;
        int max_gap = 0;
        for(auto bucket : buckets){
            if(!bucket.used)
                continue;
            
            if(bucket.minval - preBucketMax > max_gap)
                max_gap = bucket.minval - preBucketMax;
            
            preBucketMax = bucket.maxval;
        }
        
        return max_gap;
    }
};

