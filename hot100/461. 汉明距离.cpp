/*
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 231.

示例:

输入: x = 1, y = 4

输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。

*/

// 异或^, 与&，或|，非！
//先异或，在统计异或后，1的个数

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;//异或
        int count = 0;
        while(z!=0){
            z = z&(z-1);
            count ++;
        }
        return count;
    }
};
