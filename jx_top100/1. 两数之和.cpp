/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/

//说简单也不简单啊
// map的另一种用法，用于查询和存储差值。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i =0;i<nums.size();++i){
            if(mp.count(target-nums[i]) != 0){
                vector<int> res;
                res.push_back(mp[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            
            mp[nums[i]] = i;
        }
        vector<int> res;
        return res;
    }
};