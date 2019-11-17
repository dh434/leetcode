/*
给定一个仅包含小写字母的字符串，去除字符串中重复的字母，使得每个字母只出现一次。需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

示例 1:

输入: "bcabc"
输出: "abc"
示例 2:

输入: "cbacdcbc"
输出: "acdb"




*/

/*
1.遍历字符串，用map记录字符出现的最后位置；
2.第二次遍历字符串时，维护一个记录结果的栈，用vector实现；
3.维护一个map记录当前字符是否在栈里（就不需要遍历数组，看是否存在），当在栈里时，继续遍历，不在转4；
4.当栈不为空且字典序比当前元素大时，并且栈顶字符在原字符串中出现的位置比当前下标i更大，说明栈顶字符会在之后出现。弹出栈顶元素，并将栈顶元素是否在栈中的记录抹除；
5.压栈当前字符；
6.结果为vector数组中的字符顺序。
*/

// 先记录字母最后出现的位置
// 用vector来模拟栈
// 若新字母比栈顶字母小，且栈顶字母还会在以后出现，就弹出

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        map<char,int> lastPos;
        for(int i = 0;i<s.size();++i)
            lastPos[s[i]]=i;
        
        vector<char> st;
        map<char,int> record;
        for(int i =0;i<s.size();++i){
            char tar = s[i];
            if(record[s[i]] != 0)
                continue;
            else{
                while(st.size() > 0 && st.back() > tar && lastPos[st.back()] > i){
                    char temp = st.back();
                    st.pop_back();
                    record[temp]--;
                }
                
                st.push_back(tar);
                record[tar]++;
            }
        }
        
        string res="";
        for(auto c:st)
            res += c;
        
        return res;
        
    }
    
    
   
};