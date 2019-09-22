/*
给定正整数 N ，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。

如果我们可以通过上述方式得到 2 的幂，返回 true；否则，返回 false。

 

示例 1：

输入：1
输出：true
示例 2：

输入：10
输出：false
示例 3：

输入：16
输出：true
示例 4：

输入：24
输出：false
示例 5：

输入：46
输出：true
 

提示：

1 <= N <= 10^9

*/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> record;
        int num = N;
        while(num != 0){
            record.push_back(num%10);
            num /= 10;
        }
        sort(record.begin(), record.end());
        return permutation(record, 0, record.size());
    }
    
    
    bool permutation(vector<int>& record, int begin, int len){
        if(begin == len){
            if(record[0] == 0)
                return false;
            else
                return is2Exp(record);
        }else{
            
            for(int i = begin; i<len;++i){
                swap(record, i, begin);
                if(record[0] != 0){
                    bool temp = permutation(record, begin+1, len);
                    if(temp) return true;
                }
                
                
                swap(record, begin, i);
            }
            
            return false;
        }
    }
    
    
    bool is2Exp(vector<int> record){
        int sum = 0;
        
        for(auto a:record){
            sum *= 10;
            sum += a;
        }
        cout<<sum<<endl;
        if((sum & (sum-1)) == 0)
            return true;
        else
            return false;
    }
    
    void swap(vector<int>& record, int a, int b){
        int temp = record[a];
        record[a] = record[b];
        record[b] = temp;
    }
};