/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

//dp
/*
剩下的括号要么在这一组新增的括号内部，要么在这一组新增括号的外部（右侧）。
对于3
1+0+2
1+1+1
1+2+0

*/



class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0) return {};
		if (n == 1) return { "()" };
		vector<vector<string>> dp(n+1);
		dp[0] = { "" };
		dp[1] = { "()" };
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <i; j++) {
				for (string p : dp[j])
					for (string q : dp[i - j - 1]) {
						string str = "(" + p + ")" + q;
						dp[i].push_back(str);
					}
			}
		}
		return dp[n];
	}
};


//回溯
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res_list;
        vector<int> left_num_list;
        vector<int> right_num_list;
        
        res_list.push_back("(");
        left_num_list.push_back(n-1);
        right_num_list.push_back(n);
        
        int index = 0;
        for(int i=1;i<2*n;++i){
            int len = res_list.size();
            for(int j =0;j<len;++j){
                int left_num = left_num_list[j];
                int right_num = right_num_list[j];
    
                if(left_num == 0){
                    res_list.push_back(res_list[j] + ")");
                    left_num_list.push_back(left_num);
                    right_num_list.push_back(right_num-1);
                }else if(left_num < right_num){
                    res_list.push_back(res_list[j] + ")");
                    left_num_list.push_back(left_num);
                    right_num_list.push_back(right_num-1);
                    
                    res_list.push_back(res_list[j] + "(");
                    left_num_list.push_back(left_num-1);
                    right_num_list.push_back(right_num);
                }else{
                    res_list.push_back(res_list[j] + "(");
                    left_num_list.push_back(left_num-1);
                    right_num_list.push_back(right_num);
                }   
            }
            
            
            res_list.erase(res_list.begin(),res_list.begin()+len);
            left_num_list.erase(left_num_list.begin(),left_num_list.begin()+len);
            right_num_list.erase(right_num_list.begin(),right_num_list.begin()+len);
        }
        
        return res_list;
        
    }
};