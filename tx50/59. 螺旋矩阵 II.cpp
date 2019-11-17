/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        if(n == 0)
            return res;
        if(n == 1){
            res[0][0]=1;
            return res;
        }
        
        int total = n*n;
        int count = 1;
        int start = 0;
        while(start*2 < n && start*2<n)
            getMatrixCircle(res,n,n,start++,count);
        
        return res;
    }
    
    void getMatrixCircle(vector<vector<int>>& matrix, int col, int row, int start,int &count){
        
        int start_x = start;
        int start_y = start;
        int end_x = col-1-start;
        int end_y = row-1-start;
        
        //左到右
        for(int i = start;i<=end_x&&count<=col*col;++i)
            matrix[start][i] = count++;
        //xia
        if(end_y > start_y){
            for(int i = start+1;i<=end_y&&count<=col*col;++i)
                matrix[i][end_x]= count++;
        }
        //右到左
        if(end_x > start_x && end_y > start_y){
            for(int i = end_x-1;i>=start&&count<=col*col;--i)
                matrix[end_y][i]= count++;
        }
        //shang
        if(end_y-start_y >=2 && end_x > start_x){
            for(int i = end_y-1;i>start_y&&count<=col*col;--i)
                matrix[i][start]= count++;
        }
        
    }
};