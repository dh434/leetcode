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
寻找逆序对，与归并排序结合起来
*/

int InverserPairsCore(int* data, int* copy, int start, int end){
    if(start == end){
        copy[start] = data[start];
        return 0;
    }

    int length = (start + end) /2;

    int left = InverserPairsCore(data, copy, start, start + length);
    int right = InverserPairsCore(data, copy, start + length + 1, end);

    int i = start + length;
    int j = end;
    int indexCopy = end;
    int count = 0;
    while(i>= start && j>= start+length+1 ){
        if(data[i] > data[j]){
            count += (j-start-length);
            copy[indexCopy--] = data[i--];
        }else{
            copy[indexCopy--] = data[j--];
        }
    }

    for(;i>=start;--i)
        copy[indexCopy--] = data[i];
    
    for(;j>=start+length+1;--j)
        copy[indexCopy--] = data[j];
    
    return left+right+count;
}

int InversePairs(int* data, int length){
    if(data == NULL || length < 0)
        return 0;
    
    int* copy = new int[length];
    for(int i =0;i<length;++i)
        copy[i] = data[i];
    
    int count = InverserPairsCore(data,copy, 0, length-1);
    return count;
}

