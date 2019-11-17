/*
有两位极客玩家参与了一场「二叉树着色」的游戏。游戏中，给出二叉树的根节点 root，树上总共有 n 个节点，且 n 为奇数，其中每个节点上的值从 1 到 n 各不相同。

 

游戏从「一号」玩家开始（「一号」玩家为红色，「二号」玩家为蓝色），最开始时，

「一号」玩家从 [1, n] 中取一个值 x（1 <= x <= n）；

「二号」玩家也从 [1, n] 中取一个值 y（1 <= y <= n）且 y != x。

「一号」玩家给值为 x 的节点染上红色，而「二号」玩家给值为 y 的节点染上蓝色。

 

之后两位玩家轮流进行操作，每一回合，玩家选择一个他之前涂好颜色的节点，将所选节点一个 未着色 的邻节点（即左右子节点、或父节点）进行染色。

如果当前玩家无法找到这样的节点来染色时，他的回合就会被跳过。

若两个玩家都没有可以染色的节点时，游戏结束。着色节点最多的那位玩家获得胜利 ✌️。

 

现在，假设你是「二号」玩家，根据所给出的输入，假如存在一个 y 值可以确保你赢得这场游戏，则返回 true；若无法获胜，就请返回 false。

 

示例：



输入：root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
输出：True
解释：第二个玩家可以选择值为 2 的节点。
 

提示：

二叉树的根节点为 root，树上由 n 个节点，节点上的值从 1 到 n 各不相同。
n 为奇数。
1 <= x <= n <= 100

*/

//就是获取某个节点的parent，left，right的节点个数


//best
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(root->val == x) { //如果红方开局选了根节点，直接可以判断
            if(nodeCount(root->left) == nodeCount(root->right)) return false; //如果左右子树节点数相同，红方肯定比蓝方多1，必输
            else return true; //反之有一个子树超过半数，蓝方选这个子树必胜。
        }
        TreeNode* red = find(root, x); //找到红方选的节点
        int leftcount = nodeCount(red->left);
        int rightcount = nodeCount(red->right);
        if(1+leftcount+rightcount <= n / 2) return true; //如果红方选的节点为根的树的节点数<=n/2，则蓝方只需要选这个节点的父节点必胜，因为n是奇数。
        return leftcount > n/2 || rightcount > n/2; //否则如果红方选节点的左子树或右子树超过半数，蓝方就选左子树或右子树，必胜；反之必败
    }
    int nodeCount(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + nodeCount(root->left) + nodeCount(root->right);
    }
    TreeNode* find(TreeNode* root, int x) {
        if(root == nullptr) return nullptr;
        if(root->val == x) return root;
        TreeNode* tmp = find(root->left, x);
        if(tmp != nullptr) return tmp;
        return find(root->right, x);
    }
};


//my
class Solution {
private:
    int x_left_num = 0;
    int x_right_num = 0;
    int x_parent_num = 0;

    int x_left_val = 0;
    int x_right_val = 0;
    int x_parent_val = 0;
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        btreeGameWinningMoveCore(root, x, 0);

        x_parent_num = n - x_left_num - x_right_num - 1;

        if(x_left_num + x_right_num < x_parent_num-1 || 
           x_parent_num + x_right_num < x_left_num-1 ||
           x_left_num + x_parent_num < x_right_num-1)
           return true;
        else
            return false;

    }


    bool btreeGameWinningMoveCore(TreeNode* root, int x, int status){
        if(root == NULL)
            return false;
        
        if(status == 0 ){
            if( root->val == x){
                if(root->left == NULL)
                    x_left_num = -1;
                else{
                    x_left_val =root->left->val;
                    btreeGameWinningMoveCore(root->left, x, 1);
                }
                    

                if(root->right == NULL)
                    x_right_num = -1;
                else{
                    x_right_val =root->right->val;
                    btreeGameWinningMoveCore(root->right, x, 2);
                }
                    
                return true;
            }
            else{
                bool left = btreeGameWinningMoveCore(root->left, x, 0);
                if(left){
                    x_parent_val = root->val;
                    return false;
                }

                bool right = btreeGameWinningMoveCore(root->right, x, 0);
                if(right){
                    x_parent_val = root->val;
                    return false;
                }
            } 
        }else if(status == 1){
            x_left_num+=1;
            btreeGameWinningMoveCore(root->left, x, 1);
            btreeGameWinningMoveCore(root->right, x, 1);
        }else if(status == 2){
            x_right_num+=1;
            btreeGameWinningMoveCore(root->left, x, 2);
            btreeGameWinningMoveCore(root->right, x, 2);
        }

        return false;
    }
};