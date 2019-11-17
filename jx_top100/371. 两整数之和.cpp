/*
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1

*/

// 异或 得无进位得加法
// 与 得有进位的那一位，然后左移一位得进位
// 再把上述两个结果相加


class Solution {
public:
    int getSum(int a, int b) {
        
        unsigned long c = a;
        unsigned long d = b;
        while (d > 0) {
            unsigned long carry = c & d;
            c = c ^ d;
            d = carry << 1;
        }
        return (int)c;
    }
};