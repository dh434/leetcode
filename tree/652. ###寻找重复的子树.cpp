/*
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
下面是两个重复的子树：

      2
     /
    4
和

    4
因此，你需要以列表的形式返回上述重复子树的根结点。

*/

// 子树序列化
// string-hash
// hash-比对 来判断子树结构相同

struct SubTreeCount
{
	TreeNode* root;
	int count;

};

class Solution {
public:
	unordered_map<size_t, SubTreeCount> dict;
	hash<string> hasher;
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		serialize(root);
		vector<TreeNode*> res;
		for(auto const& item: dict) {
			if (item.second.count > 1) {
				res.push_back(item.second.root);
			}
		}
		return res;
	}

	size_t serialize(TreeNode* root) {
		if (root == NULL) return hasher("[]");
		char buf[2048];
		snprintf(buf, 2048, "[%d,%d,%d]", root->val, serialize(root->left), serialize(root->right));
		size_t res = hasher(buf);

		if (dict.count(res) == 0) {
			dict.insert(pair<size_t, SubTreeCount>(res, {root, 1}));
		} else {
			dict[res].count++;
		}
		return res;
	}
};

