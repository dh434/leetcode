/*
找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。

示例 1:

输入:
s = "aaabb", k = 3

输出:
3

最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2:

输入:
s = "ababbc", k = 2

输出:
5

最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n= s.size();
        if(n==0||k>n)return 0;
        if(k<2)return n;

        return f(s,k,0,n-1);
    }
    int f(string s,int k,int left,int right){
        //left,right 双指针
        if(right-left+1<k)return 0;//字符不够
        int a[26]={0};//数组，记录出现的频率
        for(int i=left;i<=right;i++){
            a[s[i]-'a']++;
        }
        while(right -left+1>=k&&a[s[left]-'a']<k){
            ++left;
        }
        while(right -left+1>=k&&a[s[right]-'a']<k){
            --right;
        }
        if(right-left+1<k) return 0;
        for(int i=left;i<=right;++i){
            if(a[s[i]-'a']<k){
                return max(f(s,k,left,i-1),f(s,k,i+1,right));
            }
        }
        return right-left+1;
    }

};