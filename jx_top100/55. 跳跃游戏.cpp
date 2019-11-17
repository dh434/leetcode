/*

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*/

//很强，在位置i，前面所有人都到不了i，就说明不能到达更后面。
//best

   bool canJump(vector<int>& nums) 
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }

// 超时
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        vector<bool> dp(nums.size(),false);
        
        int end = nums.size() -1;
        dp[end] = true;
        for(int pos = end-1;pos>=0;--pos){
            cout<<pos<<" "<<(end - pos)<<endl;
            if(nums[pos] >= (end - pos))
                dp[pos] = true;
            else{
                cout<<"s:"<<nums[pos]<<endl;
                for(int i = 1; i<=nums[pos];++i){
                    if(dp[pos+i]){
                        dp[pos]=true;
                        break;
                    }
                }
                    
            }
        }
        
        return dp[0];
        
    }
    
//     bool canJumpHelper(vector<int>& nums, int pos, int end){
//         if(pos > end)
//             return false;
//         else if(pos == end)
//             return true;
//         else{
            
            
            
//             for(int step=min(end-pos,nums[pos]);step>=1;step--){
//                 bool res = canJumpHelper(nums,pos+step,end);
//                 if(res)
//                     return true;
//             }
//         }
//         return false;
//     }
};
