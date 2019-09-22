/*
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。

示例:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
说明: 
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。

*/

//有序矩阵的查找

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        while(left < right){
            
            int mid = (left + right) >> 1;
            
            int count = countNum(matrix, mid, n);
            
            if(count < k){
                left = mid+1;
            }else{
                right = mid;
            }
            
        }
        
        return left;
        
    }
    
    
    int countNum(vector<vector<int>>& matrix, int target, int n){
        
        int i = 0;
        int j = n-1;
        int count = 0;
        while(i<n && j >= 0){
            
            if(matrix[i][j] <= target){
                count += (j+1);
                i++;
            }else{
                j--;
            }
            
        }
        
        return count;
        
        
    }
};