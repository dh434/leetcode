/*
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:

输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6

*/

// 参考85题
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0)
            return 0;
        
        int res = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int> dp(col, 0);
        
        for(int i =0;i<row;++i){
            for(int j=0;j<col;++j){
                // cout << i << " " << j << endl;
                if(matrix[i][j] == '1')
                    dp[j] = dp[j] + 1;
                else
                    dp[j] = 0;
                
            }
            
          
            
            
            int temp = largestArea(dp);
            res = max(res , temp);
        }
        
        return res;
        
    }
    
    
    int largestArea(vector<int> heights){
        
        int res = 0;
        stack<int> st;
        st.push(-1);
        
        for(int i =0;i<heights.size();++i){
            
            while(st.top()!=-1 && heights[i] <= heights[st.top()]){
                int topIndex = st.top();
                st.pop();
                res = max(res, heights[topIndex] *(i - st.top() - 1));
            }
            st.push(i);
        }
        
        int end_pos = heights.size();
        while(st.top()!=-1){
            int topIndex = st.top();
            st.pop();
            res = max(res, heights[topIndex] *(end_pos - st.top() - 1));
        }
        return res;
    }
};



// 从最简单的出发，以点(i,j)为矩形的右下角，计算其向上和向左的最大值

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if( !matrix.size())
            return 0;
        //辅助矩阵，里面存了三个值：当前行/列的长度、当前可达到的最大额矩阵面积
        vector< vector< vector<int>>> record( matrix.size(), vector<vector<int>>( matrix[0].size(), {0,0,0}));
        int res = 0;

        //dp 过程
        for( int i = 0; i < matrix.size(); i++)
            for( int j = 0; j < matrix[0].size(); j++){
                if( matrix[i][j] == '0')
                    ;
                else
                    if( i == 0 && j == 0)
                        record[i][j] = { 1, 1, 1};                
                    else if( i == 0)
                        record[i][j] = {record[i][j-1][0] + 1, 1, record[i][j-1][2] + 1};
                    else if( j == 0)
                        record[i][j] = {1, record[i-1][j][1] + 1, record[i-1][j][2] + 1};
                    else{
                        record[i][j][0] = record[i][j-1][0] + 1;
                        record[i][j][1] = record[i-1][j][1] + 1;
                        update( record, i, j);
                    }
                res = max( res, record[i][j][2]);
            }
            
        return res;
        
    }
    
    void update( vector< vector< vector<int>>>& record, int begin_i, int begin_j){
        int line_min = record[begin_i][begin_j][0];
        int row = record[begin_i][begin_j][1];
        
        for( int count = 0; count < row; count++){
            line_min = min( line_min, record[ begin_i-count][begin_j][0]);
            record[begin_i][begin_j][2] = max( record[begin_i][begin_j][2], line_min * (count + 1));
        }
    }


    
};