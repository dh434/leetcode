/*
你有一个日志数组 logs。每条日志都是以空格分隔的字串。

对于每条日志，其第一个字为字母数字标识符。然后，要么：

标识符后面的每个字将仅由小写字母组成，或；
标识符后面的每个字将仅由数字组成。
我们将这两种日志分别称为字母日志和数字日志。保证每个日志在其标识符后面至少有一个字。

将日志重新排序，使得所有字母日志都排在数字日志之前。字母日志按内容字母顺序排序，忽略标识符；在内容相同时，按标识符排序。数字日志应该按原来的顺序排列。

返回日志的最终顺序。

 

示例 ：

输入：["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
输出：["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 

提示：

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] 保证有一个标识符，并且标识符后面有一个字。

*/

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        if(logs.size() == 0)
            return logs;
        
        vector<string> numList;
        vector<string> alpList;
        
        for(auto log:logs){
            int index= 0;
            while(log[index] != ' ') index++;
            index++;
            
            if(log[index]>='0' && log[index]<='9')
                numList.push_back(log);
            else
                alpList.push_back(log);
        }
        
        sort(alpList.begin(), alpList.end(), cmp);
        
        for(auto log:numList)
            alpList.push_back(log);
        
        return alpList;
    }
    
    
    static bool cmp(string a, string b){
        int a_len =a.size();
        int b_len = b.size();
        
        int a_index= 0;
        int b_index = 0;
        while(a[a_index] != ' ') a_index++;
        while(b[b_index] != ' ') b_index++;
        
        int a_sep = a_index;
        int b_sep = b_index;
        
        a_index++;
        b_index++;
        
        while(a_index < a_len && b_index < b_len){
            if(a[a_index] == b[b_index]){
                a_index++;
                b_index++;
                continue;
            }
            
            return a[a_index] < b[b_index];
        }
        
        
        if(a_index != a_len && b_index == b_len)
            return false;
        else if(a_index == a_len && b_index != b_len)
            return true;
        else{
            return a.substr(0,a_sep) > b.substr(0,b_sep);
        }
    }
};