#include<iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <queue>
#include <stdio.h>  
#include <time.h>  
#include <windows.h>  
#include <exception> 
using namespace std;
#include <utility>


/*
示例：
[3,4,5,1,2] -> 找到最小值1

思路：
使用二分查找来减少查找的范围

特殊情况：
1. 输入的正确性；
2. 本来就是全序的数组，并没有旋转；
3. 会不会存在相同的数字，如[1,0,1,1,1]
 */

int MinInorder(int *numbers, int index1, int index2){
    int min = numbers[index1];
    for (int i = index1 + 1; i <= index2; ++ i){
        if(numbers[i] < min)
            min = numbers[i];
    }
    return min;
}


int Min(int *numbers, int length){
    if(numbers == NULL || length <= 0)
        throw new exception("Invalid parameters");
    
    int index1 = 0;
    int index2 = length -1;
    int index_min = index1;

    while(numbers[index1] >= numbers[index2]){
        if(index2 - index1 == 1){
            index_min = index2;
            break;
        }
        index_min = (index1 + index2) / 2;

        if(numbers[index1] == numbers[index2] && numbers[index1] == numbers[index_min])
            return MinInorder(numbers, index1, index2);

        
        if(numbers[index_min] >= numbers[index1])
            index1 = index_min;
        else if(numbers[index_min] <= numbers[index2]){
            index2 = index_min;
        }
    }
}   