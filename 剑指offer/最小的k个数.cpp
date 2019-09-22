#include<iostream>
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <string>

using namespace std;

/*
第一种思路：
寻找第k小的数字，排在该数字左边的就为最小的k个数
*/

/*
第二种思路：
维护最小堆，可以使用STL的set来实现，其的实现是基于红黑树来实现的
*/

typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;


void GetLeastNumbers(const vector<int> &data, intSet leastNumbers, int k){
    leastNumbers.clear();

    if(k < 1 || data.size() < k)
        return ;
    
    vector<int>::const_iterator iter = data.begin();
    for(;iter != data.end(); ++iter){
        if(leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else{
            setIterator iterGreatest = leastNumbers.begin();
            if(*iter < *(leastNumbers.begin())){
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}