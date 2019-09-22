/*
我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。

（这里，平面上两点之间的距离是欧几里德距离。）

你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

 

示例 1：

输入：points = [[1,3],[-2,2]], K = 1
输出：[[-2,2]]
解释： 
(1, 3) 和原点之间的距离为 sqrt(10)，
(-2, 2) 和原点之间的距离为 sqrt(8)，
由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
示例 2：

输入：points = [[3,3],[5,-1],[-2,4]], K = 2
输出：[[3,3],[-2,4]]
（答案 [[-2,4],[3,3]] 也会被接受。）
 

提示：

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

*/


// 1. 小顶堆
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue<point> m_queue;
        for(int i =0;i<points.size();++i){
            point p;
            p.x = points[i][0];
            p.y = points[i][1];
            
            m_queue.push(p);
        }
        
        vector<vector<int>> res;
        for(int i =0 ;i<K;++i){
            vector<int> temp;
            temp.push_back(m_queue.top().x);
            temp.push_back(m_queue.top().y);
            res.push_back(temp);
            m_queue.pop();
        }
        
        return res;
    }
    
    
    struct point{
        int x;
        int y;
        bool operator<(const point& a) const{
            return x*x+y*y > a.x * a.x + a.y*a.y;
        }
    };
    
    
};

// 2. 二分，快排partition
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int p = pow(points[0][0],2) + pow(points[0][1], 2);
        vector<vector<int> > l,m,r;
        
        for(int i = 0;i<points.size();++i){
            int temp = pow(points[i][0],2) + pow(points[i][1], 2);
            if(temp == p)
                m.push_back(points[i]);
            else if(temp < p)
                l.push_back(points[i]);
            else
                r.push_back(points[i]);
        }
        
        if(K <= l.size())
            return kClosest(l, K);
        else if(K <= l.size() + m.size()){
            l.insert(l.end(), m.begin(), m.begin() + K - l.size());
            return l;
        }else{
            vector<vector<int> > temp = kClosest(r, K-l.size()-m.size());
            l.insert(l.end(), m.begin(), m.end());
            l.insert(l.end(), temp.begin(), temp.end());
            return l;
        }
       
    }
        
};