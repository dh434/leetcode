/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 

*/

/*
异或转换法

temp = a^b
a = temp^a;
b = temp^b;


进阶
a = a^b
b = a^b
a = a^b

*/



class Solution {
public:
    string reverseWords(string s) {
       int front = 0;
        for(int i =0;i<s.size();++i){
            if(s[i] == ' '){
                reverseString(front, i-1,s);
                front = i+1;
            }
        }
        
        reverseString(front, s.size()-1,s);
        return s;
    }
    
    void reverseString(int front, int tail, string& str) {
        while (front < tail) {
            str[front] ^= str[tail];
            str[tail] ^= str[front];
            str[front++] ^= str[tail--];
        }
    }

};