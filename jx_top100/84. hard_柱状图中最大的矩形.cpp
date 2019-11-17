/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。


以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

示例:

输入: [2,1,5,6,2,3]
输出: 10

*/

// 思路1：栈，想法是：比我大的不会参与后面面积的计算，因此可以在此刻弹出，但要注意区间

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> record;
        record.push(-1);
        int maxArea = 0;
        for(int i =0;i<heights.size();++i){
            
            while(record.top()!= -1 && heights[record.top()] >= heights[i]){
                
                
                int topIndex = record.top();
                record.pop(); 
                maxArea = max(maxArea, heights[topIndex] * (i - record.top() - 1));
            }
            
            record.push(i);
                
        }
        int pos = heights.size();
        while(record.top()!= -1){
            int topIndex = record.top();
            record.pop(); 
            maxArea = max(maxArea, heights[topIndex] * (pos - record.top() - 1) );
        }
        
        return maxArea;
    }
};

// 思路2：二分，找到最小，二分计算，最坏O(n^2), 平均O(nlogn)

public class Solution {
    public int calculateArea(int[] heights, int start, int end) {
        if (start > end)
            return 0;
        int minindex = start;
        for (int i = start; i <= end; i++)
            if (heights[minindex] > heights[i])
                minindex = i;
        return Math.max(heights[minindex] * (end - start + 1), Math.max(calculateArea(heights, start, minindex - 1), calculateArea(heights, minindex + 1, end)));
    }
    public int largestRectangleArea(int[] heights) {
        return calculateArea(heights, 0, heights.length - 1);
    }
}
