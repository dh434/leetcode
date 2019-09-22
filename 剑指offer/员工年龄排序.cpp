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
// #include <exception> 
using namespace std;
#include <utility>

void SortAges(int ages[], int length){
    if(ages == NULL || length <= 0)
        return ;
    
    const int oldestage = 99;
    int timeOfAge[oldestage + 1];

    for(int i =0;i<=oldestage;++i){
        timeOfAge[i] = 0;
    }

    for(int i =0;i<length;++i){
        int age = ages[i];
        if(age < 0 || age > oldestage)
            throw new exception("age out of range");
        ++ timeOfAge[age];
    }

    int index = 0;
    for(int i =0 ;i<= oldestage;++i){
        for(int j = 0;j< timeOfAge[i];++j){
            ages[index] = i;
            ++ index;
        }
    }
}