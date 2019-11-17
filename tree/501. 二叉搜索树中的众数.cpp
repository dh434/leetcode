/*
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

*/

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
    vector<int> findMode(TreeNode* root) {
       vector<int> res;
       if(root == NULL) return res;
       
        TreeNode* pre = NULL;
        int curTime = 1;
        int maxTime = 0;
        
        inorder(root, pre, curTime, maxTime, res);
        
        return res;
    }
    
    void inorder(TreeNode* root,TreeNode* &pre, int& curTime, int& maxTime, vector<int>& res){
        
        if(root == NULL) return;
        
        inorder(root->left, pre, curTime, maxTime, res);
        
        if(pre != NULL)
            curTime = (pre->val == root->val)?curTime+1:1;
        else
            curTime = 1;
        
        if(curTime > maxTime){
            res.clear();
            maxTime = curTime;
            res.push_back(root->val);
        }else if(curTime == maxTime){
            res.push_back(root->val);
        }
        
        pre = root;
        inorder(root->right, pre, curTime, maxTime, res);
    }
};

//best
class Solution:
    def __init__(self):
        self.count = 1
        self.target = [0,0]
        self.pre = -1            # 初始判断值设为-1，用于判断第一个值（中序遍历，即最左边的值）
        
    def findMode(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        self.inorder(root)
        
        #最后一组数在递归终止后无法判断，因此要重新判断一下
        if self.count >self.target[0]:
            self.target = [self.count,self.pre]
        elif self.count==self.target[0]:
            self.target.append(self.pre)
        return self.target[1:]
    
    # 中序遍历，边遍历边判断
    def inorder(self,root):
        if not root:
            return None
        self.inorder(root.left)
        if root:
            if self.pre == -1:                 #第一个值，其实相当于初始化pre值                        
                self.pre = root.val
            elif self.pre == root.val:
                self.count += 1
            else:
                if self.count >self.target[0]:
                    self.target = [self.count,self.pre]
                elif self.count==self.target[0]:
                    self.target.append(self.pre)
                self.count = 1
                self.pre = root.val
        self.inorder(root.right)
