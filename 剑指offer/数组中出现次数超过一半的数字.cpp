#include<iostream>
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <string>

using namespace std;

/*
思路：
出现次数超过一半，那一定是排序后位于中间的数 

第一种解法：
寻找第K大的数，利用快排的思想。

*/

int Partition(int data[], int start, int end, int length){
    if(data == NULL || length<0 || start < 0 || end > length)
        throw new std::exception("Invalid Parameters");

    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);

    int small = start -1;
    for(int index=start; index<end;++index){
        if(data[index] <= data[end]){
            small++;
            if(small != index)
                Swap(&data[small], &data[index]);
        }
    }

    ++small;
    Swap(&data[small], &data[end]);
    return small;
}

bool g_bInputInvalid = false;

bool CheckInvalidArrary(int* numbers, int length){
    g_bInputInvalid = false;
    if(numbers == NULL || length < 0)
        g_bInputInvalid = true;
    
    return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int number){
    int time = 0;
    for(int i =0 ;i<length;++i){
        if(numbers[i] == number)
            time ++;
    }

    bool isMoreThanHalf = true;
    if(time * 2 <= length){
        g_bInputInvalid = false;
        isMoreThanHalf = false;
    }

    return isMoreThanHalf;
}

int MoreThanHalfNum(int* numbers, int length){
    if(CheckInvalidArrary(numbers, length))
        return 0;
    
    int middle = length >> 1;
    int start = 0;
    int end = length -1;
    int index = Partition(numbers, start, end, length);
    while(index != middle){
        if(index > middle){
            end = index -1;
            index = Partition(numbers, start, end, length);
        }else{
            start = index + 1;
            index = Partition(numbers, start, end, length);
        }
    }

    int result = numbers[middle];
    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;
    
    return result;
}


/*
第二种解法：
目标数字出现次数比其他数字的次数还要多。

因此我们可以在遍历数组的时候保存两个值：一个是数字，一个是次数
当我们遍历到下一个数字的时候，如果和前一个数字相同，则次数加一，否则减一。
如果次数为零，则保存下一个数字，并把次数设为1.

由于目标数字比其他数字的出现次数之和还要多，因此要找的数字就是最后一个将次数置为1的数字。

*/

int MoreThanHalfNum_2(int* numbers, int length){
    if(CheckInvalidArrary(numbers, length))
        return 0;

    int result = numbers[0];
    int times = 1;
    for(int i = 1;i<length;++i){
        if(times == 0){
            result = numbers[i];
            times = 1;
        }else if(numbers[i] == result)
            times ++;
        else
        {
            times --;
        }
    }

    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;
    
    return result;
}