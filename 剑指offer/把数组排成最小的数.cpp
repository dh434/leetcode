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

思路：
自定义比较方式，mn vs nm
*/

const int g_MaxNumberLength = 10;

char* g_StrCombine1 = new char[g_MaxNumberLength* 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength* 2 + 1];


int compare(const void* strNumber1, const void* strnumber2){
    strcpy(g_StrCombine1, *(const char**)strNumber1);
    strcat(g_StrCombine1, *(const char**)strnumber2);

    strcpy(g_StrCombine2, *(const char**)strnumber2);
    strcat(g_StrCombine2, *(const char**)strNumber1);
}

void PrintMinNumber(int* numbers, int length){
    if(numbers == NULL || length < 0)
        return ;
    
    char** strNumbers = (char**)(new int[length]);
    for(int i = 0 ;i<length;++i){
        strNumbers[i] = new char[g_MaxNumberLength + 1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }

    qsort(strNumbers, length, sizeof(char*), compare);

    for(int i = 0;i<length; ++i){
        printf("%s", strNumbers[i]);
    }
    printf("\n");

    for(int i =0;i<length;++i){
        delete[] strNumbers[i];
    }
    delete[] strNumbers;
}
