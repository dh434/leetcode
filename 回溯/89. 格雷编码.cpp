/*
解释:
00 - 0
01 - 1
11 - 3
10 - 2

对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。

00 - 0
10 - 2
11 - 3
01 - 1
示例 2:

输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。

*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1);
        result[0] = 0;
        for(int i = 1; i <= n; i++){
            int e = 1 << (i - 1);                           //i - 1位结果前增加一位1
            for(int j = result.size() - 1; j >= 0; j--){    // 镜像排列
                result.push_back(e + result[j]);
            }
        }
        return result;
        
    }
};