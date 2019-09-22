//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。




class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1_size = num1.size();
        int num2_size = num2.size();
        
        int index1 = num1_size - 1;
        int index2 = num2_size - 1;
        int carry  = 0;
        string res = "";
        
        while(index1 >=0 || index2 >=0){
            int temp1 = index1 >=0? num1[index1] -'0':0;
            int temp2 = index2 >=0? num2[index2] - '0':0;
            
            int temp = temp1 + temp2 + carry;
            carry = temp/10;
            temp = temp%10;
            
            res = to_string(temp) + res;
            
            index1 --;
            index2 --;
        }
        return carry > 0 ?"1"+res : res;
         
    }
};