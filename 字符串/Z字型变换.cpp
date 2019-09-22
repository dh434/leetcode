/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G

*/


// 找规律的题目


class Solution {
public:
    
    string convert(string s, int numRows) {

		if (numRows == 1) return s;

		vector<string> rows(min(numRows, int(s.size()))); // 防止s的长度小于行数
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) {// 当前行curRow为0或numRows -1时，箭头发生反向转折
				goingDown = !goingDown;
			}
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) {// 从上到下遍历行
			ret += row;
		}

		return ret;
	}

    
//     string convert(string s, int numRows) {
        
//         if(s.size() == 0 || numRows == 0|| numRows == 1)
//             return s;
        
//         queue<char> q[numRows];
//         int col_index = 1;
//         int s_index = 0;
//         int s_len = s.size();
        
//         while(s_index < s_len){
//             if(col_index == 1){
//                 for(int i =0 ;i<numRows;++i){
//                     q[i].push(s[s_index]);
//                     s_index ++;
//                     if(s_index > s_len-1){
//                         break;
//                     }
//                 }
//             }else{
//                 int target_col = numRows - col_index%numRows;
//                 q[target_col].push(s[s_index]);
//                 s_index ++;
//             }
            
//             col_index ++;
//             if(col_index == numRows)
//                 col_index = 1;
            
//         }
//         string res = "";
//         for(int i =0 ;i<numRows;++i){
//             while(!q[i].empty()){
//                 res += q[i].front();
//                 q[i].pop();
//             }
//         }
        
//         return res;
//     }
};