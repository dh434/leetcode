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
把一个整数减去1， 再和原来的整数做与运算，会把该整数最右边的一个1变成0. 

相关：
1.判断一个整数是不是2的整数次方。
2. 输入两个整数，计算需要改变m二进制表示中的多少为才能变成n。先异或，再计算1的个数。
 */


int NumberOf1(int n){
    int count = 0 ;
    while(n){
        ++count;
        n = (n - 1) & n;
    }
    return n;
}