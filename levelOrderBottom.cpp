#include<vector>
#include<iostream>
#include<queue>
using namespace std;

// definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
			result.insert(result.begin(),curH);
			while (!nexHier.empty()) {
				curHier.push(nexHier.front());
				nexHier.pop();

			}
		}
		return result;
	}
};