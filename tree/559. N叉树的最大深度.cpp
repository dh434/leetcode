/*
给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

例如，给定一个 3叉树 :


我们应返回其最大深度，3。

说明:

树的深度不会超过 1000。
树的节点总不会超过 5000。

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        
        if(root == NULL)
            return 0;
        
        
        return maxDepthCore(root);
    }
    
    int maxDepthCore(Node* root){
        if(root == NULL)
            return -1;
        
        if(root->children.size() == 0)
            return 1;
        
        int maxDeep = 0;
        
        for(auto c : root->children)
            maxDeep = max(maxDeep, maxDepthCore(c));
        
        return maxDeep+1;
    }
    
};