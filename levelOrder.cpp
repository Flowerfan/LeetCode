#include<vector>
#include<queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (!root) return result;
		vector<int> curH;
		queue<TreeNode*> curHier, nexHier;
		curHier.push(root);
		while (!curHier.empty()) {
			curH.clear();
			while (!curHier.empty()) {
				if (curHier.front()->left != NULL)
					nexHier.push(curHier.front()->left);
				if (curHier.front()->right != NULL)
					nexHier.push(curHier.front()->right);
				curH.push_back(curHier.front()->val);
				curHier.pop();
			}
			result.push_back(curH);
			while (!nexHier.empty()) {
				curHier.push(nexHier.front());
				nexHier.pop();

			}
		}
		return result;
	}
};

//recursive method

//vector<vector<int>> ret;
//
//void buildVector(TreeNode *root, int depth)
//{
//	if (root == NULL) return;
//	if (ret.size() == depth)
//		ret.push_back(vector<int>());
//
//	ret[depth].push_back(root->val);
//	buildVector(root->left, depth + 1);
//	buildVector(root->right, depth + 1);
//}
//
//vector<vector<int> > levelOrder(TreeNode *root) {
//	buildVector(root, 0);
//	return ret;
//}