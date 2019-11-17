/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

*/

// 该排序的就不要犹豫，先对下界排序
// 需要先对其进行排序

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int len = intervals.size();
        if(len == 0)
            return res;
        
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        
        for(int i =1;i<len;++i){
            vector<int> pre = res.back();
            vector<int> cur = intervals[i];
            if(pre[1] >= cur[0]){
                res.back()[1] = max(pre[1], cur[1]);
            }else{
                res.push_back(cur);
            }
            
        }
        
        return res;
    }
    
    static bool cmp(const vector<int>&a,const vector<int>&b )
    {
        // if(a[0]==b[0])
        //     return a[1]>b[1];
        return a[0]<b[0];
    }


};

//利用两趟hash扫描实现O(n)算法
/*
感觉官方给出的答案不是最优解，其实可以构造一个{{区间坐标=>区间次序}}的映射并顺序扫描它，每当得到一个完整的封闭区间时便输出，来实现O(n)时间的算法，大致过程如下：
第一趟扫描输入的区间数组，以头尾坐标为key,索引值+1为val存入一个map中（其中头坐标为正，尾坐标为负，这样就能保证一个完整封闭区间里的坐标值之和一定为0）；
第二趟遍历这个map（这里利用了c++map的有序性），不断累加区间坐标值，每当坐标值之和为零时便输出这个区间（即上一次为0之后的key和当前的key），并重新开始下一个区间的扫描。

*/


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size()==0 || intervals.size()==1){
        return intervals;
    }

    map<int,int> orders;
    for(int i=0; i<intervals.size(); i++){
        int s = intervals[i][0];
        int e = intervals[i][1];
        if(orders.find(s)==orders.end()){
            orders[s] = 0;
        }
        if(orders.find(e)==orders.end()){
            orders[e] = 0;
        }
        orders[s] += i+1;
        orders[e] += -i-1;
    }

    int sum = 0;
    vector<vector<int>> ret;
    vector<int> cur;
    for(std::map<int,int>::iterator it=orders.begin(); it!=orders.end(); it++){
        if(sum==0){
            cur.push_back(it->first);
            sum += it->second;
            if(sum==0){
                cur.push_back(it->first);
                ret.push_back(cur);
                cur.clear();
            }
            continue;
        }
        sum += it->second;
        if(sum==0){
            cur.push_back(it->first);
            ret.push_back(cur);
            cur.clear();
        }
    }

    return ret;
}
