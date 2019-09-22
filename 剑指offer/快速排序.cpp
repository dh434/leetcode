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

int randomInRange(int start,int end)
{
    srand (time(NULL));
    return rand() % (end-start+1) + start; 

}

void Swap(int* num1,int* num2)
{
    int temp=*num1;
    *num1=*num2;
    *num2=temp;
}

int Partition(int data[], int start, int end , int length){
    if(data == NULL || length <= 0 || start < 0 || end >= length)
        throw new std::exception("Invalid Parameters");

    int index = randomInRange(start,end);
    Swap(&data[end], &data[index]);

    int small = -1;
    for(int i = 0;i<length;++i){
        if(data[i] < data[index]){
            ++small;
            if(small != i){
                Swap(&data[i], &data[small]);
            }
        }
    }

    ++small;
    Swap(&data[small], &data[end]);

    return small;
}

void QuickQort(int data[], int length, int start, int end){
    if (start == end)
        return ;

    int index = Partition(data, length, start, end);
    if(index > start)
        QuickQort(data,length, start,index-1);
    if(index < end)
        QuickQort(data,length, index+1, end);
}