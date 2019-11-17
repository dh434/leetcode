/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

*/

/*
时间复杂度
统计频率，需要遍历一遍数组，所需要的时间复杂度为O(n), 
hashmap的插入、查找的时间复杂度为O(1), 所以统计频率过程时间复杂度为O(n).

遍历hashmap的时间复杂度时间复杂度O(n)，
维护元素个数为k的小顶堆时间复杂度为O(logk)， 
这个过程时间复杂度为O(nlogk).

把优先队列转换为数组时间复杂度为O(k).
综上所述，整体时间复杂度为 O(nlogk).

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        
        for(auto num : nums)
            mp[num] += 1;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        
        int count = 0;
        for(auto iter : mp){
            if(pq.size() < k)
                pq.push(make_pair(iter.first, iter.second));
            else{
                if(pq.top().second < iter.second){
                    pq.pop();
                    pq.push(make_pair(iter.first, iter.second));
                }
            }
        }
        
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
    
    struct cmp {
        bool operator()(const pair<int,int> a, const pair<int,int> b) const
        {
            return a.second > b.second;
        }
    };


};