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
题目：
长度为n的数组，数字都在0-n-1的范围里，但某几个数字是重复的，找出任意重复的数字

思路：
1. 排序
2. 哈希
3. 数字放在对应的下标里
*/

bool idDuplicate(int numbers[], int length, int* duplication){
    if(numbers == NULL || length <= 0)
        return false;
    
    for(int i=0;i<length;++i){
        if(numbers[i] <0 || numbers[i] > length-1)
            return false;
    }

    for(int i =0;i<length;++i){
        while(numbers[i] != i){
            if(numbers[i] == numbers[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }else{
                //swap numbers[i] 和 numbers[numbers[i]]
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
    }
    return false;
}