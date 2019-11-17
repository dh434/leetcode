/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

*/

//递归每个节点只会被访问一次，因此时间复杂度为 O(N)，其中 N 表示节点数目。
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string temp="";
        binaryTreePathsCore(root,temp,res);
        return res;
    }
    
    void binaryTreePathsCore(TreeNode* root, string& temp, vector<string>& res){
        
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            temp += to_string(root->val);
            res.push_back(temp);
            return ;
        }
        
        
        if(root->left){
            string next = temp;
            next += to_string(root->val);
            next += "->";
            binaryTreePathsCore(root->left,next,res);
        }
        
        
        if(root->right){
            string next = temp;
            next += to_string(root->val);
            next += "->";
           
            binaryTreePathsCore(root->right,next,res);
        }
        return ;
    }
    
    
};

//best
class Solution {
    public void construct_paths(TreeNode root, String path, LinkedList<String> paths) {
        if (root != null) {
            path += Integer.toString(root.val);
            if ((root.left == null) && (root.right == null))  // 当前节点是叶子节点
                paths.add(path);  // 把路径加入到答案中
            else {
                path += "->";  // 当前节点不是叶子节点，继续递归遍历
                construct_paths(root.left, path, paths);
                construct_paths(root.right, path, paths);
            }
        }
    }

    public List<String> binaryTreePaths(TreeNode root) {
        LinkedList<String> paths = new LinkedList();
        construct_paths(root, "", paths);
        return paths;
    }



//迭代

class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        LinkedList<String> paths = new LinkedList();
        if (root == null)
            return paths;

        LinkedList<TreeNode> node_stack = new LinkedList();
        LinkedList<String> path_stack = new LinkedList();
        node_stack.add(root);
        path_stack.add(Integer.toString(root.val));
        TreeNode node;
        String path;
        while (!node_stack.isEmpty()) {
            node = node_stack.pollLast();
            path = path_stack.pollLast();
            if ((node.left == null) && (node.right == null))
                paths.add(path);
            if (node.left != null) {
                node_stack.add(node.left);
                path_stack.add(path + "->" + Integer.toString(node.left.val));
            }
            if (node.right != null) {
                node_stack.add(node.right);
                path_stack.add(path + "->" + Integer.toString(node.right.val));
            }
        }
        return paths;
    }
}
