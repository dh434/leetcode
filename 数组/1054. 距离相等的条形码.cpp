/*
在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。

请你重新排列这些条形码，使其中两个相邻的条形码 不能 相等。 你可以返回任何满足该要求的答案，此题保证存在答案。

 

示例 1：

输入：[1,1,1,2,2,2]
输出：[2,1,2,1,2,1]
示例 2：

输入：[1,1,1,1,2,2,3,3]
输出：[1,3,1,3,2,1,2,1]
 

提示：

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000

*/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int len = barcodes.size();
        int tail = len - 1;
        int head = 1;
        
        if(len <= 2)
            return barcodes;
        
        map<int,int> count;
        for(auto a:barcodes) count[a]++;
        
        
        //大顶堆
        priority_queue<pair<int,int>, vector<pair<int,int> >, less<pair<int,int> > > pq; 
        for(auto a:count) pq.push(make_pair(a.second, a.first));
        
        vector<int> res(len);
        int odd = 1,even = 0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
             while(p.first>0 && even<len){
                res[even] = p.second;
                p.first --;
                even += 2;
            }
           
            
            while(p.first>0 && odd<len){
                res[odd] = p.second;
                p.first --;
                odd += 2;
            }
            
            
        }
        
        return res;
        
    }
};