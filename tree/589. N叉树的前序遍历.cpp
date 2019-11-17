/*
给定一个 N 叉树，返回其节点值的前序遍历。

例如，给定一个 3叉树 :

返回其前序遍历: [1,3,5,6,2,4]。

 

说明: 递归法很简单，你可以使用迭代法完成此题吗?


*/

// 注意前序遍历 要先放右再左

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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        
        
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* cur = st.top();
            
            res.push_back(cur->val);
            
            st.pop();
            int len = cur->children.size();
            for(int i =len-1;i>=0;--i)
                st.push(cur->children[i]);
            
        }
        return res;
    }
};