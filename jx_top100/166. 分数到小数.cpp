/*
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

如果小数部分为循环小数，则将循环的部分括在括号内。

示例 1:

输入: numerator = 1, denominator = 2
输出: "0.5"
示例 2:

输入: numerator = 2, denominator = 1
输出: "2"
示例 3:

输入: numerator = 2, denominator = 3
输出: "0.(6)"

*/

/*

这道题细节很多
测试样例	解释
\frac{0}{1} 
1
0
​	
 	被除数为 0。
\frac{1}{0} 
0
1
​	
 	除数为 0，应当抛出异常，这里为了简单起见不考虑。
\frac{20}{4} 
4
20
​	
 	答案是整数，不包括小数部分。
\frac{1}{2} 
2
1
​	
 	答案是 0.5，是有限小数。
\frac{-1}{4} 
4
−1
​	
  或 \frac{1}{-4} 
−4
1
​	
 	除数被除数有一个为负数，结果为负数。
\frac{-1}{-4} 
−4
−1
​	
 	除数和被除数都是负数，结果为正数。
\frac{-2147483648}{-1} 
−1
−2147483648
​	
 	转成整数时注意可能溢出。

https://leetcode-cn.com/problems/fraction-to-recurring-decimal/solution/fen-shu-dao-xiao-shu-by-leetcode/
*/


//可以直接先求整数部分的，然后再单独求小数部分

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if(numerator == 0)
            return "0";
        
        string res = "";
        if(numerator <0 ^ denominator <0 )
            res += "-";
        
        long dividend = numerator;
        long divisor = denominator;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        res += to_string(dividend/divisor);
        long remainder = dividend%divisor;
        if(remainder == 0)
            return res;
        
        res += ".";
        map<int,int> mp;
        while(remainder!=0){
            // cout<<remainder<<endl;
            
            if(mp.find(remainder) != mp.end()){
                res.insert(mp[remainder], "(");
                res += ")";
                break;
            }
            mp[remainder] = res.size();
            remainder *= 10;
            res += to_string(remainder/divisor);
            remainder = remainder%divisor;
        }
       
        return res;
        
    }
};
