/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，
采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，
你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。


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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        
        queue<TreeNode*> mq;
        mq.push(root);
        
        TreeNode* p;
        while(!mq.empty()){
            p = mq.front();
            mq.pop();
            
            if(p == NULL)
                res.push_back("null");
            else{
                mq.push(p->left);
                mq.push(p->right);
                res.push_back(to_string(p->val));
            }
        }
        
        int end = res.size() - 1;
        while(end >= 0 && res[end] == "null") end--;
        
        string target = "";
        
        for(int i =0;i<=end;++i){
            target += res[i];
            if(i != end)
                target += ",";
        }
        
        return target;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> target;
        string temp ="";
        for(auto c:data){
            if(c == ','){
                target.push_back(temp);
                temp = "";
            }else{
                temp += c;
            }
        }
        if(temp != "")
            target.push_back(temp);
        
        
        if(target.empty())
            return nullptr;
        
        queue<TreeNode*> mq;
        TreeNode* root = new TreeNode(stoi(target[0]));
        mq.push(root);
        int count = 0;
        int len =target.size();
        while(count < len){
            
            TreeNode* cur = mq.front();
            mq.pop();
            // cout<<cur->val<<endl;
            count++;
            int left_pos = count;
            if(left_pos < len && target[left_pos] != "null") {
                // cout<<"left " << target[left_pos]<<endl;
                TreeNode* temp = new TreeNode(stoi(target[left_pos]));
                cur->left = temp;
                mq.push(temp);
            }
            
            count++;
            int right_pos = count;
            if(right_pos < len && target[right_pos] != "null") {
                // cout<<"right " << target[right_pos]<<endl;
                TreeNode* temp = new TreeNode(stoi(target[right_pos]));
                cur->right = temp;
                mq.push(temp);
            }
            
        }
        
        return root;
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));