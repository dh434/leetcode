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
查找排序的数组中k出现的次数。

利用二分查找来找到第一个和最后一个k，复杂度O(logn)
*/

int GetFirstK(int* data, int length, int k, int start, int end){
    if(start > end)
        return -1;
    
    int middleIndex = (start + end) / 2;
    int middleNum = data[middleIndex];

    if(middleNum == k){
        if(middleIndex == 0 || (middleIndex > 0 && data[middleIndex-1]!=k))
            return middleIndex;
        else
            end = middleIndex-1;
    }else if(middleNum > k){
        end = middleIndex-1;
    }else{
        start = middleIndex + 1;
    }

    return GetFirstK(data, length, k, start, end);
}

int GetLastK(int* data, int length, int k, int start, int end){
    if(start > end)
        return -1;
    
    int middleIndex = (start + end) / 2;
    int middleNum = data[middleIndex];

    if(middleNum == k){
        if(middleIndex == length-1 || (middleIndex < length-1 && data[middleIndex+1]!=k))
            return middleIndex;
        else
            start = middleIndex+1;
    }else if(middleNum > k){
        end = middleIndex-1;
    }else{
        start = middleIndex + 1;
    }

    return GetLastK(data, length, k, start, end);
}

int GetNumberOfK(int* data, int length, int k){
    int number = 0;
    if(data != NULL && length > 0){
        int first = GetFirstK(data, length, k, 0, length-1);
        int last = GetLastK(data, length, k, 0, length-1);

        if(first > -1 && last > -1)
            number = last - first + 1;
    }

    return number;
}