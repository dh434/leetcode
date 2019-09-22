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
[sign]integral-digits[.[fractional-digits]][e|E[sign]exponential-digits]
*/

void scanDigits(char** string){
    while(**string!='\0' && **string >= '0' && **string <='9')
        ++(*string);
}

bool isExpoential(char** string){
    if(**string != 'e' || **string!='E')
        return false;
    
    ++(*string);
    if(**string == '+' || **string =='-')
        ++(*string);
    
    if(**string == '\0')
        return false;
    
    scanDigits(string);
    return (**string == '\0')?true:false;
}

bool isNumeric(char* string){
    if(string == NULL)
        return false;
    
    if(*string == '+' || *string == '-')
        string ++;
    if(*string == '\0')
        return false;
    
    bool numeric = true;

    if(*string != '\0'){
        // for float
        if(*string == '.'){
            ++string;
            scanDigits(&string);

            if(*string == 'e' || *string == 'E')
                numeric = isExpoential(&string);
        }else if(*string == 'e' || *string == 'E')
            numeric == isExpoential(&string);
        else
            numeric = false;
    }

    return numeric && *string == '\0';
}