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
#include<limits>  

//哈希表


class CharStatics
{
    private:
    int occurrent[256];
    int index;

    public:
    CharStatics() : index(0){
        for(int i =0;i<256;++i)
            occurrent[i] = -1;
    }

    void Insert(char ch){
        if(occurrent[ch] == -1)
            occurrent[ch] = index;
        else if(occurrent[ch] >=0 )
            occurrent[ch] = -2;
        
        ++index;
    }

    char FirstAppearingOnce(){
        char ch = '\0';
        int minIndex = numeric_limits<int>::max();
        for(int i=0;i<256;++i){
            if(occurrent[i] >= 0 && occurrent[i] < minIndex){
                ch = (char)i;
                minIndex = occurrent[i];
            }
        }
        return ch;
    }
}