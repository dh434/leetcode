/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。

*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int len = nums.size();
        
        for(int i = 0; i<len - 1;++i){
            for(int j = 0; j < len -1 - i;++j){
                if(cmp(nums[j], nums[j+1])){
                    int temp = nums[j];
                    nums[j ] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
        
        
        string res = "";
        for(int i = 0;i<len;++i)
            res += to_string(nums[i]);
        
        int index = 0;
        int res_len = res.size();
        while(res[index] == '0' && index < res_len -1 ) index ++;
        
        res = res.substr(index, res_len-index+1);
        
        return res;
        
    }
    
    bool cmp(int a, int b){
        
        string ab = to_string(a) + to_string(b);
        string ba = to_string(b) + to_string(a);
        
        if(ab < ba)
            return true;
        else
            return false;
    }
};

//best

ool cmp(const string & a,const string &b){
    int min_len = min(a.length(),b.length());
    for(int i = 0;i<min_len;++i){
        if(a[i]!=b[i]) return a[i]>b[i];
    }
    for(int i = min_len;i < a.length();++i){
        if(a[i]!=b[0]) return a[i]>b[0];
    }
    for(int i = min_len;i < b.length();++i){
        if(b[i]!=a[0]) return a[0]>b[i];
    }
    return a+b>b+a?true:false;
}

class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        bool all_zero = true;
        for(auto n:nums){
            if(n!=0) all_zero = false;//判断是否是全0
            vs.push_back(to_string(n));
        }
        if(all_zero) return "0";
        sort(vs.begin(),vs.end(),cmp);
        string res;
        for(auto s:vs){
            res+=s;
        }
        return res;
    }
};

