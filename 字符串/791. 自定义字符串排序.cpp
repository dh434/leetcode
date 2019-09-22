/*
字符串S和 T 只包含小写字符。在S中，所有字符只会出现一次。

S 已经根据某种规则进行了排序。我们要根据S中的字符顺序对T进行排序。更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。

返回任意一种符合条件的字符串T。

示例:
输入:
S = "cba"
T = "abcd"
输出: "cbad"
解释: 
S中出现了字符 "a", "b", "c", 所以 "a", "b", "c" 的顺序应该是 "c", "b", "a". 
由于 "d" 没有在S中出现, 它可以放在T的任意位置. "dcba", "cdba", "cbda" 都是合法的输出。
注意:

S的最大长度为26，其中没有重复的字符。
T的最大长度为200。
S和T只包含小写字符。

*/

//统计词频

class Solution {
public:
    string customSortString(string S, string T) {
        map<char,int> record;
        for(int i = 0;i<S.size();++i)
            record[S[i]]  = i;
        
        
        int index = S.size();
        vector<vector<int> > targetList;
        for(auto a:T){
            if(record.count(a) == 0)
                targetList.push_back({a-'a', index++});
            else
                targetList.push_back({a-'a', record[a]});
        }
        
        
        sort(targetList.begin(), targetList.end(), cmp);
        
        string res = "";
        for(auto a: targetList)
            res += ('a'+a[0]);
        return res;
    }
    
    static bool cmp(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
};

//
string customSortString(string S, string T) {
        int pos[S.length()];
        for (int i = 0; i < S.length(); ++i) {
            pos[i] = S[i];
        }
        int count[26] = {0};
        for (int i = 0; i < T.length(); ++i) {
            count[T[i] - 97]++;
        }
        string res;
        for (int i = 0; i < S.length(); ++i) {
            res.append(count[pos[i] - 97], pos[i]);
            count[pos[i] - 97] = 0;
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i]) {
                res.append(count[i], i + 97);
            }
        }
        return res;
    }

作者：liyupi
链接：https://leetcode-cn.com/problems/custom-sort-string/solution/cshi-jian-onsuan-fa-by-liyupi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。