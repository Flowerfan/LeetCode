#include<vector>
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
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		else if (!(root->left) && !(root->right)) return 1;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
	}
};