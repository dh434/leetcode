/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        
//         vector<int> res(len);
        
//         for(int i =0;i<len;++i){
//             int index = (i+k)%len;
//             res[index] = nums[i];
//         }
        
        vector<bool> check(len, false);
        
        int count = 0;
        int targetIndex = k%len;
        int preNum = nums[0];
        while(count < len){
            cout<<targetIndex<<endl;
            int temp = nums[targetIndex];
            nums[targetIndex]= preNum;
            preNum = temp;
            
            check[targetIndex] = true;
            
            ++count;
            if(count == len)
                break;
            
            targetIndex = (targetIndex+k)%len;
            while(targetIndex < len && check[targetIndex]){
                targetIndex = (targetIndex+1)%len; 
                preNum = nums[targetIndex];
                targetIndex = (targetIndex+k)%len; 
            }
                
        }
        
        
    }
};

//使用反转

// 和旋转字符串是一样的

// 原始数组                  : 1 2 3 4 5 6 7
// 反转所有数字后             : 7 6 5 4 3 2 1
// 反转前 k 个数字后          : 5 6 7 4 3 2 1
// 反转后 n-k 个数字后        : 5 6 7 1 2 3 4 --> 结果

public class Solution {
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }
    public void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}

// 复杂度分析
// 时间复杂度：O(n)O(n) 。 nn 个元素被反转了总共 3 次。
// 空间复杂度：O(1)O(1) 。 没有使用额外的空间。
