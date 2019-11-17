/*
给定一个整数 n，返回 n! 结果尾数中零的数量。

示例 1:

输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
示例 2:

输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.
说明: 你算法的时间复杂度应为 O(log n) 。

*/

// 多比划比划

class Solution {
public:
    int trailingZeroes(int n) {
        
        int res = 0;
        long base = 1;
        while(base <= n){
            base*=5;
            res += (n/base);
        }
        
        return res ;
    }
};