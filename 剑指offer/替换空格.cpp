#include<iostream>
using namespace std;

/*
示例：
"We are friend" -> "We%02are%02friend"

思路：
在原字符串的基础上扩展，需保证的是原字符串有足够的空间。
先遍历一遍，确认有几个空格，再从后面开始，用双指针的思想替换，从而减少移动次数。

复杂度：
O(n)

测试用例：
1.输入字符串包括空格（开头，中间，结尾，连续多个）
2. 无空格
3.特殊输入：空字符串，空间不够，只是一个空格，只是多个空格
 */


void replaceBlank(char* string[], int length){

    if(string == NULL || length <= 0)
        return ;
    
    int originalLength = 0;
    int newLength = 0;
    int numOfBlank = 0;
    int i =0;
    while(string[i] != "\0"){
        ++ originalLength;

        if (string[i] == " ")
            numOfBlank ++;
        ++i;
    }

    newLength = originalLength + 2 * numOfBlank;
    if (newLength > length)
        return ;
    
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
        if(string[indexOfOriginal] == " "){
            string[indexOfNew -- ] = "0";
            string[indexOfNew -- ] = "2";
            string[indexOfNew -- ] = "%";
        }else
        {
            string[indexOfNew -- ] = string[indexOfOriginal];
        }
        
        -- indexOfOriginal;
    }
}