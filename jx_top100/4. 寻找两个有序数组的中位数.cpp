/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

*/

// 划分区间，首先确定，我们在最短的数组上进行二分查找
// 其次使用2n的思想，就是取中位数的时候，不用考虑左右两边

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(n > m)
            return findMedianSortedArrays(nums2, nums1);
        
        
        int LMax1, LMax2, RMin1, RMin2, lo = 0, hi = 2*n;
        
        while(lo <= hi){
            int cut1 = (lo+hi)/2;
            int cut2 = m+n - cut1;
            
            LMax1 = cut1 == 0? INT_MIN:nums1[(cut1-1)/2];
            LMax2 = cut2 == 0? INT_MIN:nums2[(cut2-1)/2];
            
            RMin1 = cut1 == 2*n? INT_MAX:nums1[cut1/2];
            RMin2 = cut2 == 2*m? INT_MAX:nums2[cut2/2];
            
            if(LMax1 > RMin2)
                hi = cut1-1;
            else if(RMin1 <  LMax2)
                lo = cut1+1;
            else
                break;
        }
        // cout<< LMax1 << " "<<LMax2<< " "<<RMin1<< " "<<RMin2<<endl;
        
        return (max(LMax1, LMax2) + min(RMin1, RMin2))/2.0;
        
    }
};