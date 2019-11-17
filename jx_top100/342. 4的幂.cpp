
/*
给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。

示例 1:

输入: 16
输出: true
示例 2:

输入: 5
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？

*/


// 找一下规律： 4 的幂次方的数的二进制表示 1 的位置都是在奇数位。

// 1010101010101010101010101010101
// 将这个二进制数转换成 16 进制表示：0x55555555 。



class Solution {
    public boolean isPowerOfFour(int num) {
        if (num <= 0)
			return false;
        //先判断是否是 2 的幂
		if ((num & num - 1) != 0)
			return false;
        //如果与运算之后是本身则是 4 的幂   // 或者计算往右移位的次数
		if ((num & 0x55555555) == num)
			return true;
		return false;
    }
}
