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
只包含因子2，3，5的数称为丑数，求第1500个丑数

利用乘法，顺序生成前1500个丑数
*/

int GetUglyNumber(int index){
    if(index < 0)
        return 0;
    
    int *uglynumbers = new int[index];
    uglynumbers[0] = 1;
    int uglyIndex = 1;

    int* pMultiply2 = uglynumbers;
    int* pMultiply3 = uglynumbers;
    int* pMultiply5 = uglynumbers;

    while(uglyIndex < index){
        int min_number = min(*pMultiply2 * 2, *pMultiply2 *3, *pMultiply5*5);
        uglynumbers[uglyIndex] = min_number;

        while(*pMultiply2 * 2 <= min_number)
            ++ pMultiply2;
        while(*pMultiply3 * 3 <= min_number)
            ++ pMultiply3;
        while(*pMultiply5 * 5 <= min_number)
            ++ pMultiply5;
        
        ++ uglyIndex;

    }

    int ugly = uglynumbers[uglyIndex - 1];
    delete[] uglynumbers;
    return ugly;
}