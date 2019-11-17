/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

*/

class Solution {
public:
    string decodeString(string s) {
        
        stack<int> st_num;
        stack<string> st_string;
        
        int num = 0;
        
        int cur = 0;
        
        while(cur < s.size()){
            char target = s[cur];
            
            if(target>='0' && target <='9'){
                int num = target-'0';
                
                cur++;
                
                while(s[cur] != '['){
                    num*=10;
                    num+=(s[cur] - '0');
                    cur++;
                }
                st_num.push(num);
                cur--;
            }
            else if(target == '['){
                st_string.push("[");
            }
            else if(target == ']'){
                
                string temp = "";
                while(!st_string.empty() && st_string.top() != "["){
                    temp  = st_string.top() + temp;
                    st_string.pop();
                }
                st_string.pop();
                
                
                temp = repeat(temp, st_num.top());
                st_num.pop();
                
                st_string.push(temp);
            }else{
                
                string temp;
                temp.push_back(target);
                st_string.push(temp);
            }
            cur++;
        }
        
        
        
        string res = "";
        
        while(!st_string.empty()){
            res = st_string.top() +res;
            st_string.pop();
        }
        
        return res;
        
        
    }
    
    string repeat(string a, int k){
        string res = "";
        for(int i =0;i<k;++i)
            res += a;
        return res;
    }
};