/*
给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :

返回其后序遍历: [5,6,3,2,4,1].

 

说明: 递归法很简单，你可以使用迭代法完成此题吗?

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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        
        
        stack<pair<Node*,bool>> st;
        st.push(make_pair(root,false));
        
        while(!st.empty()){
            
            Node* cur = st.top().first;
            bool visit = st.top().second;
            st.pop();
            if(visit){
                res.push_back(cur->val);
            }else{
                st.push(make_pair(cur, true));
                int len = cur->children.size();
                for(int i=len-1;i>=0;--i)
                    st.push(make_pair(cur->children[i], false));
            }
            
        }
        
        return res;
        
    }
};