/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

*/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() -1;
        
        while(l < r){
            
            while(l<r && !isAlphaOrNum(s[l])) l++;
            while(l<r && !isAlphaOrNum(s[r])) r--;
            // cout<<l << " " << r <<endl;
            if(toLower(s[l]) != toLower(s[r]))
                return false;
            
            l++;
            r--;
        }
        
        return true;
    }
    
    
    bool isAlphaOrNum(char c){
        if((c>='a' && c <= 'z') ||(c>='A' && c <= 'Z') || (c>='0' && c <= '9'))
            return true;
        else
            return false;
    }
    
    char toLower(char c){
        if(c>='A' && c <= 'Z')
            return c + ('a' - 'A');
        else
            return c;
    }
};