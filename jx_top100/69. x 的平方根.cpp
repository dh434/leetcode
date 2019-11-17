/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

*/

// 左中位数：（l+r）/2
// 右中位数： l+（r-l+1)/2

// 在本题中，取左中位数会陷入死循环
// 注意 mid*mid 会溢出

class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 1 || x == 0)
            return x;
        
        int l = 1;
        int r = x /2;//闭区间
        
        while(l < r){
            long mid = l + (r- l + 1)/2;
            long temp = mid*mid;
            if( temp > x)
                r = mid-1;
            else if(temp < x)
                l = mid;
            else
                return (int)mid;
        }
        
        return l;
    }
};