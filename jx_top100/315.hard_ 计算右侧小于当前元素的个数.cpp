/*
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例:

输入: [5,2,6,1]
输出: [2,1,1,0] 
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.

*/

// 二分的思想

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        
        vector<int> index_vec(nums.size());
        vector<int> res(nums.size());
        int index = 0;
        for(auto a:nums){
            res[index] =0;
            index_vec[index] = index;
            index ++;
        }
            
        countSmallerHelper(index_vec, nums, 0, nums.size(), res);
        
        return res;
    }
    
    void countSmallerHelper(vector<int>& index_vec, vector<int>& nums, int left, int right, vector<int>& res){
        
        if(right - left<= 1)
            return ;
        
        int mid = (left + right) / 2;
        
        // cout<< left << " " << mid << " " << right<<endl;
        
        countSmallerHelper(index_vec, nums, left, mid, res);
        countSmallerHelper(index_vec, nums, mid, right, res);
        
        int n = mid-1;
        int m = right-1;
        // cout << "mid:" << nums[mid] << endl;
        for(int n=mid-1;n>=left;--n){
            
            while(m >= mid && nums[index_vec[n]] <= nums[index_vec[m]]) m--;
            // cout << index_vec[n] << " " << index_vec[m]<<endl;
            if(nums[index_vec[n]] > nums[index_vec[m]] && m >= mid)
                res[index_vec[n]] +=  (m - mid + 1);
            
        }
        
        vector<int> temp(right - left);
        n = left;
        m = mid;
        int count = 0;
        
        while(n < mid && m < right){
            if(nums[index_vec[n]]< nums[index_vec[m]]){
                temp[count++] = index_vec[n++];
            }else{
                temp[count++] = index_vec[m++];
            }
        }
        
        while(n < mid) temp[count++] = index_vec[n++];
        while(m < right) temp[count++] = index_vec[m++];
        
        
        for(int i = left;i<right;++i){
            index_vec[i] = temp[i-left];
        }
    }
};