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
翻转单词顺序
先旋转句子中所有字符，再翻转每个单词内字符
*/

void Reverse(char* pBegin, char*pEnd){
    if(pBegin == NULL || pEnd == NULL)
        return ;
    
    while(pBegin < pEnd){
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin ++;
        pEnd--;
    }
    return ;
}

char* ReverseSentense(char* pData){
    if(pData == NULL)
        return NULL;
    
    char* pBegin = pData;
    char* pEnd = pData;
    while(*pEnd != '\0')
        pEnd ++;
    pEnd --;

    //整个句子
    Reverse(pBegin, pEnd);

    //每个单词
    pBegin = pEnd = pData;
    while(*pBegin != '\0'){
        if(*pBegin == ' '){
            pBegin ++;
            pEnd ++;
        }else if(*pEnd == ' ' || *pEnd == '\0'){
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }else{
            pEnd++;
        }
    }

    return pData;
}



/*
左旋字符串

*/


char* LeftRotateString(char* pStr, int n){
    if(pStr != NULL){
        int nLength = static_cast<int>(strlen(pStr));
        if(nLength >0 && n >0 && n<nLength){
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n -1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;


            Reverse(pFirstStart, pFirstEnd);
            Reverse(pSecondStart, pSecondEnd);

            Reverse(pFirstStart, pSecondEnd);
        }
    }

    return pStr;
}