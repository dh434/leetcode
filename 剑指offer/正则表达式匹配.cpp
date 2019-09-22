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

bool match(char* str, char* pattern){
    if(str == NULL || pattern == NULL)
        return false;
    return matchCore(str,pattern);
}

bool matchCore(char* str, char* pattern){
    if(*str == '\0' && *pattern == '\0')
        return true;
    
    if(*str!='\0' && *pattern == '\0')
        return false;
    
    if(*(pattern + 1) == '*'){
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str+1, pattern+2) || matchCore(str, pattern+2) || matchCore(str+1, pattern);
        else
            return matchCore(str, pattern+2);
    }

    if(*str == *pattern || (*pattern == '.' && *str != '\0')){
        return matchCore(str+1, pattern+1);
    }

    return false;
}