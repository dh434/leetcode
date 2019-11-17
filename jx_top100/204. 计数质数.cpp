/*
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/

//剔除法，做一个数组

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n,true);
        
        for(int i = 2;i*i<n;++i){
            if(!isPrime[i]) 
                continue;
            
            for(int j = i*i;j<n;j+=i)
                isPrime[j] = false;
        }
        
        int count = 0;
        for(int i =2;i<n;++i)
            if(isPrime[i]) count++;
        
        return count;
    }
    
//     bool isPrime(int num){
//         if(num <= 1) return false;
        
//         for(int i =2;i*i<=num;++i)
//             if(num%i == 0) return false;
        
//         return true;
//     }
};