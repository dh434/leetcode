/*
给定数组 A，我们可以对其进行煎饼翻转：我们选择一些正整数 k <= A.length，然后反转 A 的前 k 个元素的顺序。我们要执行零次或多次煎饼翻转（按顺序一次接一次地进行）以完成对数组 A 的排序。

返回能使 A 排序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * A.length 范围内的有效答案都将被判断为正确。

 

示例 1：

输入：[3,2,4,1]
输出：[4,2,4,3]
解释：
我们执行 4 次煎饼翻转，k 值分别为 4，2，4，和 3。
初始状态 A = [3, 2, 4, 1]
第一次翻转后 (k=4): A = [1, 4, 2, 3]
第二次翻转后 (k=2): A = [4, 1, 2, 3]
第三次翻转后 (k=4): A = [3, 2, 1, 4]
第四次翻转后 (k=3): A = [1, 2, 3, 4]，此时已完成排序。 
示例 2：

输入：[1,2,3]
输出：[]
解释：
输入已经排序，因此不需要翻转任何内容。
请注意，其他可能的答案，如[3，3]，也将被接受。
 

提示：

1 <= A.length <= 100
A[i] 是 [1, 2, ..., A.length] 的排列

*/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        
        int len = A.size();
        vector<int> res;
        while(len > 1){
            
            int max_pos = getMaxPos(A, len);
            if(max_pos == len - 1){
                len --;
                continue;
            }
            else if(max_pos == 0){
                reverse(A, len);
                res.push_back(len);
                len --;
            }else{
                reverse(A, max_pos + 1);
                res.push_back(max_pos + 1);
                reverse(A, len);
                res.push_back(len);
                len --;
            }
        }
        return res;
        
    }
    
    int getMaxPos(vector<int>& A,int len){
        int pos = 0;
        int max= 0;
        int index = 0;
        while(index < len){
            if(A[index] > max){
                max = A[index];
                pos = index;
            }
            
            index++;
        }
        
        return pos;
    }
    
    void reverse(vector<int>& A,int len){
        int i = 0, j = len -1;
        while(i < j){
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            
            i++;
            j--;
        }
    }
};