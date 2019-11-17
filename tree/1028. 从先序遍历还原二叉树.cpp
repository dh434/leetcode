/*
我们从二叉树的根节点 root 开始进行深度优先搜索。

在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。

如果节点只有一个子节点，那么保证该子节点为左子节点。

给出遍历输出 S，还原树并返回其根节点 root。

 

示例 1：

输入："1-2--3--4-5--6--7"
输出：[1,2,5,3,4,6,7]
示例 2：



输入："1-2--3---4-5--6---7"
输出：[1,2,5,3,null,6,null,4,null,7]
示例 3：



输入："1-401--349---90--88"
输出：[1,401,null,349,88,90]
 

提示：

原始树中的节点数介于 1 和 1000 之间。
每个节点的值介于 1 和 10 ^ 9 之间。
在真实的面试中遇到过这道题？

*/

//hard

// 特别注意的是：
// 1.数字可能不为一位数
// 2. 开头的数字也是


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
    TreeNode* recoverFromPreorder(string S) {
        int s_len = S.size();
        if(s_len == 0)
            return nullptr;

        
        stack<TreeNode*> node;
        stack<int> line;
        int num = 0;
        int cur_index = 0;
        while(cur_index < s_len && S[cur_index] != '-'){
            num*=10;
            num+= (S[cur_index] -'0');
            cur_index+=1;
        }

        TreeNode* root = new TreeNode(num);
        node.push(root);
        line.push(0);
        
        int cur_line_count = 0;
        while(cur_index < s_len){

            if( S[cur_index] == '-'){
                
                while(cur_index < s_len && S[cur_index] == '-'){
                    cur_line_count ++;
                    cur_index ++;
                }
                cur_index -= 1;
            }else{
                num = 0;
                while(cur_index < s_len && S[cur_index] != '-'){
                    num*=10;
                    num+= (S[cur_index] -'0');
                    cur_index+=1;
                }
                cur_index -= 1;

                while(cur_line_count <= line.top()){
                    line.pop();
                    node.pop();
                }

                if(cur_line_count == line.top() + 1){
                    if(node.top()->left == NULL){
                        TreeNode* temp = new TreeNode(num);
                        node.top()->left = temp;
                        node.push(temp);
                        line.push(cur_line_count);
                    }else{
                        TreeNode* temp = new TreeNode(num);
                        node.top()->right = temp;
                        node.pop();
                        line.pop();
                        node.push(temp);
                        line.push(cur_line_count);
                    }
                }
                cur_line_count = 0;
            }
            cur_index += 1;
        }

        return root;
    }
};