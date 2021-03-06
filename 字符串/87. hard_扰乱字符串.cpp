/*
给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。

下图是字符串 s1 = "great" 的一种可能的表示形式。

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。

例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
我们将 "rgeat” 称作 "great" 的一个扰乱字符串。

同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
我们将 "rgtae” 称作 "great" 的一个扰乱字符串。

给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。

示例 1:

输入: s1 = "great", s2 = "rgeat"
输出: true
示例 2:

输入: s1 = "abcde", s2 = "caebd"
输出: false

*/

//dp O(n^4) O(n^3) 
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int s1_len = s1.size();
        int s2_len = s2.size();
        
        vector<vector<vector<bool>>> matrix(s1_len, vector<vector<bool>>(s1_len, vector<bool>(s1_len)));
        
        for(int i =0;i<s1_len;++i)
            for(int j=0;j<s2_len;++j)
                matrix[0][i][j] = (s1[i] == s2[j]);
        
        
        for(int i =1;i<s1_len;++i){
            int len = i+1;
            for(int m =0;m<s1_len-i;++m){
                
                for(int n =0;n<s1_len-i;++n){
                    bool mn_res = false;
                    for(int k =1;k<len;++k){
                        mn_res = (matrix[k-1][m][n] && matrix[len-k-1][m+k][n+k]) || 
                                 (matrix[k-1][m][n+len-k] && matrix[len-k-1][m+k][n]);
                        if(mn_res)
                            break;
                    }
                    
                    matrix[i][m][n] = mn_res;
                    
                }
            }
        } 
        
        return matrix[s1_len-1][0][0];
    }
};


//含记忆的递规-java
public boolean isScramble(String s1, String s2) {
    HashMap<String, Integer> memoization = new HashMap<>();
    return isScrambleRecursion(s1, s2, memoization);
}

public boolean isScrambleRecursion(String s1, String s2, HashMap<String, Integer> memoization) {
    	//判断之前是否已经有了结果
		int ret = memoization.getOrDefault(s1 + "#" + s2, -1);
		if (ret == 1) {
			return true;
		} else if (ret == 0) {
			return false;
		}
		if (s1.length() != s2.length()) {
			memoization.put(s1 + "#" + s2, 0);
			return false;
		}
		if (s1.equals(s2)) {
			memoization.put(s1 + "#" + s2, 1);
			return true;
		}

		int[] letters = new int[26];
		for (int i = 0; i < s1.length(); i++) {
			letters[s1.charAt(i) - 'a']++;
			letters[s2.charAt(i) - 'a']--;
		}
		for (int i = 0; i < 26; i++)
			if (letters[i] != 0) {
				memoization.put(s1 + "#" + s2, 0);
				return false; 
			}

		for (int i = 1; i < s1.length(); i++) {
			if (isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i))) {
				memoization.put(s1 + "#" + s2, 1);
				return true;
			}
			if (isScramble(s1.substring(0, i), s2.substring(s2.length() - i))
					&& isScramble(s1.substring(i), s2.substring(0, s2.length() - i))) {
				memoization.put(s1 + "#" + s2, 1);
				return true;
			}
		}
		memoization.put(s1 + "#" + s2, 0);
		return false;
	}
