/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"

*/

//找一下规律

// c++   string res = string(num1_len + num2_len, '0');


class Solution {
public:
    string multiply(string num1, string num2) {
        int num1_len = num1.size();
        int num2_len = num2.size();
        
        if(num1_len == 0 && num2_len ==0)
            return "0";
        
        string res = string(num1_len + num2_len, '0');
        for(int i = num1_len-1; i>=0;--i){
            for(int j=num2_len-1;j>=0;--j){
                int temp = (res[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] = temp%10 + '0';
                res[i+j] += temp/10;
            }
        }
        
        
        for(int i =0;i<num1_len + num2_len;++i){
            if(res[i] != '0')
                return res.substr(i);
        }
        
        return "0";
        
    }
    
    
    
    
};