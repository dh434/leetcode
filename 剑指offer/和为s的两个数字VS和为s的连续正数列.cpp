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
和为s的两个数字

在一个递增的数组里，查找两个数，使其和为s

*/

bool findNumbersWithSum(int data[], int length, int sum, int* num1, int* num2){
    bool found = false;
    if(length < 1 || num1 == NULL || num2 == NULL)
        return found;
    
    int ahead = length -1;
    int behind = 0;

    while(ahead > behind){
        long long cursum = data[ahead] + data[behind];

        if(cursum == sum){
            *num1 = data[ahead];
            *num2 = data[behind];
            found = true;
            break;
        }
        else if(cursum > sum)
            --ahead;
        else
            ++behind;
    }

    return found;
}


/*
和为s的连续正序列
*/

void PrintContinueSequence(int small, int big){
    for(int i =small;i<= big;++i){
        printf("%d",i);
    }
    printf("\n");
}

void FindContinuesSequence(int sum){
    if(sum < 3)
        return ;
    
    int small =1;
    int big = 2;
    int middle = (1+sum) / 2;
    int cursum = small + big;

    while(small < middle){
        if(cursum == sum)
            PrintContinueSequence(small, big);
        
        while(cursum > sum && small < big){
            cursum -= small;
            small ++;

            if(cursum == sum)
                PrintContinueSequence(small , big);
        }
        big ++;
        cursum+=big;
    }
}