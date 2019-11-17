/*
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

示例 1:

输入: "1 + 1"
输出: 2
示例 2:

输入: " 2-1 + 2 "
输出: 3
示例 3:

输入: "(1+(4+5+2)-3)+(6+8)"
输出: 23
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

*/

class Solution {
public:
    int calculate(string s) {
        stack<int> numStack;
        stack<char> optStack;
        
        int num = 0;
        int index = 0;
        int len = s.size();
        bool has_num = false;
        
        while(index < len){
            char c = s[index];          
            // cout<<c<<endl;
            if(c == ' '){
                index++;
                continue;
            }
            else if(c>='0' && c<='9'){
                num *= 10;
                num += (c-'0');
                index++;
                has_num = true;
            }
            else if(c == '('){
                optStack.push(c);
                index++;
            }else if(c == ')'){
                if(has_num){
                    numStack.push(num);
                    num=0;
                    has_num = false;
                }
                
                while(optStack.top() != '('){
                    // cout<<"XXXX:"<<optStack.top()<<endl;
                    cal(numStack, optStack);
                }
                // cout<<"dd:"<<numStack.top()<<endl;
                optStack.pop();
                index++;
            }else{
                if(has_num){
                    numStack.push(num);
                    num=0;
                    has_num = false;
                }
                
                while(!optStack.empty() && priority(optStack.top()) >= priority(c))
                    cal(numStack, optStack);
                optStack.push(c);
                index++;
                    
            }
            // cout<<numStack.size() << " " << optStack.size()<<endl;
        }
        if(has_num)
            numStack.push(num);
        
        while(!optStack.empty())
            cal(numStack, optStack);
        
        return numStack.top();
    }
     int priority(char c){
        switch(c){
            case '+':case '-': return 1;
            case '*':case '/': return 2;
            case '(': return 0;
            default:return 0;
        }
        return 0;
    }
    
    
    void cal(stack<int> &numStack, stack<char> &optStack){
        
        char opt = optStack.top();
        int num1 = numStack.top();
        numStack.pop();
        int num2 = numStack.top();
        numStack.pop();
        optStack.pop();
        
        if(opt=='+')
            numStack.push(num1+num2);
        else if(opt =='-')
            numStack.push(num2-num1);
        else if(opt =='*')
            numStack.push(num1*num2);
        else if(opt =='/')
            numStack.push(num2/num1);
    }
};