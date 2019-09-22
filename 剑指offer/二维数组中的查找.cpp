#include<iostream>
using namespace std;

/*

示例：
1   2   8   9
2   4   9   12
4   7   10  13
6   8   11  15

思路：
从右上角的数开始比较，目的是找到二分查找的点，减少比较次数和混乱。

测试用例：
1. 数组中的最大值和最小值，介于二者之间
2. 没有查找的数字
3. 特殊输入：空指针
 */


bool searchInMatrix(int* matrix, int rows, int columns, int num){
    bool found = false;

    if( matrix != NULL && rows > 0 && columns > 0){
        int row = 0;
        int column  = columns - 1;

        while(row < rows && column >=0){
            if(matrix[row * columns + column] == num){
                found = true;
                break;  
            }else if (matrix[row * columns + column] > num)
            {
                --column;
            }else
            {
                --row;
            }
        }
    }

    return found;
}

