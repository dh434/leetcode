






//best
/*
该思路应该适用于求无排序数组中是否存在n元递增数组，
只需在原始数组遍历中的将当前值num[i]与incArr各项循环对比更新即可

“递增的x元子序列”通用解法：维护子序列数组

维护一个子序列数组win，该数组长度最长为3。初始化win为[nums[0]]，随后遍历数组。

遇到比子序列最后一位大的元素，则可以将其加入子序列中
若比子序列最后一位要小，则需要更新该子序列，使得子序列“尽量小”，

例如子序列为[1,4]时，此时遇到元素2，那么需要将子序列更新为[1,2]，
因为在子序列“尽量小”的情况下才更容易遇到递增元素；
另一个例子是[4, 5], 遇到元素1,此时需要更新为[1,5]，
可以发现这时候子序列并不严格对应最终的递增子序列，
但是在只需要长度的情况下可以不用考虑子序列的元素情况。

空间复杂度：O(1) 最长为3的子序列数组
时间复杂度：O(n) 遍历数组时，最多对子序列数组进行2次遍历

*/



class Solution:
    def increasingTriplet(self, nums: [int]) -> bool:       
        if len(nums) < 3:
            return False

        win = [nums[0]]

        for num in nums:
            if num > win[-1]:
                win.append(num)
                if len(win) >= 3:
                    return True
            else:
                i = len(win) - 1
                while i > 0 and win[i-1] >= num:
                    i -= 1
                
                win[i] = num
        return False


// 空间不符合
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        vector<bool> minCompare(nums.size(), false);
        
        int min_num = nums[0];
        for(int i=1;i<nums.size();++i){
            if(nums[i] > min_num)
                minCompare[i] = true;
            else{
                min_num = nums[i];
            }
        }
        cout << min_num<<endl;
        
        int max_num = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;--i){
            cout << nums[i] << " " << max_num<< endl;
            if(nums[i] < max_num && minCompare[i]){
                return true;
            }
            else{
                max_num = nums[i];
            }
        }
        
        return false;
    }
};