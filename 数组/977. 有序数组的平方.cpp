/*
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

 

示例 1：

输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
示例 2：

输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]
 

提示：

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A 已按非递减顺序排序。

*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0;
        vector<int> res;
        
        if(A.size() == 0)
            return res;
        
        
        while(i < A.size() && A[i] <= 0) i++;
        int j = i;
        i--;
        
        while(i>=0 && j < A.size()){
            
            if(A[i]*A[i] < A[j]*A[j]){
                res.push_back(A[i]*A[i]);
                i--;
            }else{
                res.push_back(A[j]*A[j]);
                j++;
            }
        }
        
        while(i>=0){
            res.push_back(A[i]*A[i]);
            i--;
        }
        
        while(j < A.size()){
            res.push_back(A[j]*A[j]);
            j++;
        }
        return res;
    }
};