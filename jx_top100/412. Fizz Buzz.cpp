/*
写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

示例：

n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n,"0");
        
        map<int,string> mp;
        mp[3] = "Fizz";
        mp[5] = "Buzz";
        
        for(int i=0;i<n;++i){
            string temp = "";
            for(auto item : mp)
                if((i+1)%item.first == 0) temp+=item.second;
            if(temp == "")
                res[i] = to_string(i+1);
            else
                res[i] = temp;
            
        }
        
        return res;
    }
};

//best
for(int i=1;i<=n;i++){
    res[i-1]=to_string(i);
}
for(int i=3;i<=n;i+=3){
    res[i-1]="Fizz"
}
for(int i=5;i<=n;i+=5){
    res[i-1]="Buzz"
}
for(int i=15;i<=n;i+=15){
    res[i-1]="FizzBuzz"
}