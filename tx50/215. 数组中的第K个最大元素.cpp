/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int low = 0, high = nums.size() - 1, mid = 0;
        while (low <= high) {
           mid = partition(nums, low, high);
           if (mid == k - 1) return nums[mid];
           else if (mid > k - 1) high = mid - 1;
           else low = mid + 1;
        }
        //  实际上返回 -1 代表没有第 k 大的数，这里不存在
        return -1;
    }
    
    int partition(vector<int>& nums,int left, int right){
        int index = randomRange(left,right);
        swap(nums, index, right);
        
        int small = left-1;
        for(int i = left;i<=right;++i){
            if(nums[i] > nums[right]){
                small ++;
                if(i != small)
                    swap(nums, i, small);
            }
        }
        
        small++;
        swap(nums, right, small);
        return small;
    }
    
    int randomRange(int start, int end){
        srand(time(NULL));
        return rand() %(end-start+1)+start;
    }
    
    void swap(vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};