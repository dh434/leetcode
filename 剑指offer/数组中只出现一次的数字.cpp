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

unsigned int FindFirstBitIs1(int num){
    int index = 0;
    while((num&1)!=0 && (index < 8 * sizeof(int))){
        num = num >> 1;
        ++ index;
    }
    return index;
}

bool IsBit1(int num, unsigned int index){
    num = num >> index;
    return (num & 1);
}

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2){
    if(data == NULL || length < 0)
        return;
    
    int resultExclusiveOR = 0;
    for(int i =0;i<length;++i)
        resultExclusiveOR ^= data[i];
    
    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

    *num1 = 0;
    *num2 =0;
    for(int j =0;j<length;++j){
        if(IsBit1(data[j], indexOf1))
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }
}