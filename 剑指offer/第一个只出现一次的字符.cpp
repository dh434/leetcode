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
char 8位， 256种可能
*/

char FirstNotRepeatingChar(char* pString){
    if(pString == NULL)
        return '\0';

    
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for(unsigned int i = 0;i<tableSize;++i)
        hashTable[i] = 0;
    
    char* pHashKey = pString;
    while(*pHashKey != '\0')
        hashTable[*(pHashKey++)] ++;
    
    pHashKey = pString;
    while(*pHashKey != '\0'){
        if(hashTable[*pHashKey] == 1)
            return *pHashKey;
        
        ++ pHashKey;
    }

    return '\0';

}