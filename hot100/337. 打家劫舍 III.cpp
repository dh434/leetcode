/*
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

*/

//超时
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        vector<int> prices;
        queue<TreeNode*> mq;
        mq.push(root);
        while(!mq.empty()){
            int len = mq.size();
            for(int i =0;i<len;++i){
                TreeNode* temp = mq.front();
                mq.pop();
                if(temp == NULL){
                    prices.push_back(0);
                }else{
                    prices.push_back(temp->val);
                    mq.push(temp->left);
                    mq.push(temp->right);
                }
            }
        }
        
        int end = prices.size() - 1;
        while(end >= 0 && prices[end] == 0) end--;
        cout<<end<<endl;
        vector<long> dp(end+1);
        
        for(int i =end;i>=0;--i){
            dp[i] = getMax(prices, dp, end, i); 
        }
        
        return (int)dp[0];
        
    }
    
    
    long getMax(vector<int> prices,vector<long> dp, int end, int pos){
        long left1 = 2*pos+1 <= end? dp[2*pos+1] : 0;
        long right1 = 2*pos+2 <= end? dp[2*pos+2] : 0;
        
        
         long left1_1 = 2*(pos+1)+1 <= end? dp[2*(pos+1)+1] : 0;
         long left1_2 = 2*(pos+1)+2 <= end? dp[2*(pos+1)+2] : 0;
        
         long right1_1 = 2*(pos+2)+1 <= end? dp[2*(pos+2)+1] : 0;
         long right1_2 = 2*(pos+2)+2 <= end? dp[2*(pos+2)+2] : 0;
        //1
        long temp1 = (long)prices[pos] + left1_1 + left1_2 + right1_1 + right1_2;
        // long temp2 = left1_1 + left1_2 + right1;
        // long temp3 = left1 + right1_1 + right1_2;
        long temp4 = left1+right1;
        
        return max(temp1, temp4);
        
    }
};


//best
/*
在每个结点的金额非负的情况下，且要保证取值结点不相邻，只可能有四种最大的取值方式：

1. 结点2 + 结点3
2. 结点1 + 结点4 + 结点5 + 结点6 + 结点7
3. 结点2 + 结点6 + 结点7
4. 结点3 + 结点4 + 结点5
那么我们可以自底向上递归进行这个dp运算，令dp[i]代表以i结点为根节点的子树的最大偷窃金额值，计算结束后将dp值直接保存在i结点的val值当中返回。可以推出状态转移方程为：

dp[root] = Max(dp[l]+dp[r], root.val+dp[ll]+dp[lr]+dp[rr]+dp[rl], dp[l]+dp[rl]+dp[rr], dp[r]+dp[lr]+dp[rl]);
分别对应上述四种情况。而观察发现，在dp[l]和dp[r]的计算中实际已经包含了dp[ll]、dp[lr]、dp[rr]、dp[rl]的取舍情况，因此可以简化为前两种情况。状态转移方程简化为：

dp[root] = Max(dp[l]+dp[r], root.val+dp[ll]+dp[lr]+dp[rr]+dp[rl]);

*/

int treeSolution::rob(TreeNode* root)
{
	if (root == nullptr)return 0;
	vector<int > ans;
	ans = robDp(root);
	return max(ans[0], ans[1]);
}
vector<int > robDp(TreeNode* root)
{
	//返回数组第一位为包含根节点最大值，第二位为不包含根节点最大值
	if (root == 0)return{ 0, 0 };
	vector<int > left = robDp(root->left);//左子树的信息
	vector<int > right = robDp(root->right);//右子树的信息
	vector<int > temp(2, 0);
	temp[0] = root->val + left[1]+right[1];//包含根节点的最大值
	temp[1] = max(max(left[0] + right[0], left[1] + right[1]),max(left[0]+right[1],left[1]+right[0]));//不包含根节点的最大值
	return temp;
}
