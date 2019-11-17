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
#include <utility>
#include <cmath>
using namespace std;


/*
介绍：
实现base的exponent次方，不得使用库函数，不用考虑大数问题。


思路：
1. 注意输入值的范围，base可以为负数，0，整数，而且exponent也可以为负数，则需要做倒数，就需要注意0的问题。
2. 简单的做法下，负数会导致无限循环。
3. 迭代乘法需要n次，二分的乘法只需要logn。
4. 注意异常情况的表示：返回值，全部变量和exception。
5.注意浮点数的比较，不能直接比较相等。
 */

bool equal(double num1, double num2){
    if((num1 - num2 > -0.0000001) && (num2 -num1 < 0.0000001) ){
        return true;
    }else{
        return false;
    }
}

double PowerWithUnsignedExponent(double base, unsigned int exponent){
    double result = 1.0;
    for(int i =0 ;i<= exponent;++i)
        result *= base;
    return result;
}

double Quick_PowerWithUnsignedExponent(double base, unsigned int exponent){

    if(exponent == 0)
        return 1.0;
    if(exponent == 1)
        return base;
    
    double result = Quick_PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1){
        result *= base;
    }
    return result;
}

bool g_InvalidInput = false;
double Power(double base, int exponent){
    g_InvalidInput = false;
    if(equal(base, 0.0) && exponent < 0){
        g_InvalidInput = true;
        return 0;
    }

    unsigned int absExponent = (unsigned int)(exponent);
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);
    
    double result = PowerWithUnsignedExponent(base, absExponent);
    if(exponent < 0)
        result = 1.0/result;
    
    return result;
}