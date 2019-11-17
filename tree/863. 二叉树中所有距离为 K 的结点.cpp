/*
给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。

返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。

 

示例 1：

输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

输出：[7,4,1]

解释：
所求结点为与目标结点（值为 5）距离为 2 的结点，
值分别为 7，4，以及 1



注意，输入的 "root" 和 "target" 实际上是树上的结点。
上面的输入仅仅是对这些对象进行了序列化描述。
 

提示：

给定的树是非空的，且最多有 K 个结点。
树上的每个结点都具有唯一的值 0 <= node.val <= 500 。
目标结点 target 是树上的结点。
0 <= K <= 1000.

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == NULL)
            return {};
        
        vector<int> res;
        distanceKCore(root, target, K, -1, res);
        
        return res;
    }
    
    int distanceKCore(TreeNode* root, TreeNode* target, int K, int count,vector<int>& res){
        
        if(root == NULL)
            return -1;
        // cout<< root->val << " " << count<<endl;
        
        
        if(count == K){
            res.push_back(root->val);
            return -1;
        }
        
        if(root == target){
            
            if(K == 0){
                res.push_back(root->val);
                return 1;
            }
            
            distanceKCore(root->left, target, K, 1,res);
            distanceKCore(root->right, target, K, 1,res);
            
            return 1;
        }else{
            if(count != -1)
                count ++;
            
            int left = distanceKCore(root->left, target, K, count ,res);
            if(left == K){
                res.push_back(root->val);
                return -1;
            }
            int right = -1;
            if(left != -1)
                right =  distanceKCore(root->right, target, K, left+1 ,res);
            else
                right =  distanceKCore(root->right, target, K, count,res);
            
            if(right == K){
                res.push_back(root->val);
                return -1;
            }
            if(right != -1){
                left =  distanceKCore(root->left, target, K, right+1 ,res);
                return  right+1;
            }
            else if(left != -1)
                return left+1;
            else 
                return -1;
        }
        
    }
};


// best
/*
首先，题目要求获得二叉树中到目标节点为K的所有节点。我们从两个方面来考虑：

如果我们要找的节点是目标节点的子节点。这个问题很简单，直接DFS就可以了。我们定义一个方法：获取到根节点距离为K的子节点：
public void getKFromRoot(TreeNode root,int k){
        if (root == null) return ;
        if (k == 0) res.add(root.val);
        getKFromRoot(root.left,k -1);
        getKFromRoot(root.right,k -1);
    }
调用时，只需要把target作为参数传入就可以了。

2.如果要找的节点不是子节点。那肯定在他的__先祖链上__或者在__先祖链的另一课子树__上。在此思路上，我们深度优先遍历即可。注意在方法返回时，如果不是目标节点我们直接返回-1表示没找到。如果找到目标节点，则返回K，这样向祖先递归时，我们不停的衰减K，就可以找到祖先链上的那个节点。同时，祖先链上的某个节点也知道需要在另一棵子树上找距离为多少的节点。
需要注意的是：因为我们已经提前知道要去当前节点的left或者right为根的子树里去寻找，所以在传递距离参数的时候要记得减去1（当前节点的left或者right子节点本身占用1的距离）。

public int dfs(TreeNode root,TreeNode target){
        if (root == null) return -1;
        if (root.val == target.val){
            getKFromRoot(root,k);
            return k;
        } 
        int l = dfs(root.left,target);
        int r = dfs(root.right,target);
        
        if (l < 0 && r < 0){
            return -1;
        }else if (l > 0){
            if (l == 1) res.add(root.val);
            else  getKFromRoot(root.right, l - 2);
            return l - 1;
        }else {
            if (r == 1) res.add(root.val);
            else getKFromRoot(root.left,r - 2);
            return r - 1;
        }
    }


*/


//利用节点的深度来计算节点之间的距离

/*
前序遍历，哈希记录各个节点的深度和父节点集合。

节点a与节点b的最近公共父节点为c，h为节点的深度，则a与b的距离为distance(a,b)=h(a)+h(b)-2*h(c)distance(a,b)=h(a)+h(b)−2∗h(c)

依据这个公式再遍历一次树就可以了，满足条件的就输出。

python
class Solution:
    def distanceK(self, root, target, K):
        h, f = {}, {}
        def g(r, i, fs):
            if r:
                h[r.val] = i
                f[r.val] = [r.val] + fs     #让最近的父节点排在最前面
                g(r.left, i + 1, f[r.val])
                g(r.right, i + 1 , f[r.val])
        g(root, 0, [])
        ans, t = [], target.val
        for i in h:
            for common in f[t]:             #由近到远遍历目标点的父节点
                if common in f[i]:          #如果存在共同父节点且满足条件
                    if h[t] + h[i] - 2 * h[common] == K:
                        ans += [i]          #就加入答案
                    break
        return ans


*/