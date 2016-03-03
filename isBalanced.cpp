#include<vector>
#include<algorithm>
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
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		int leftDepth = depth(root->left);
		int rightDepth = depth(root->right);
		if (abs(leftDepth - rightDepth) > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}

	int depth(TreeNode* node) {
		if (!node) return 0;
		return max(depth(node->left), depth(node->right)) + 1;
	}
};

//clearner solution same method


//class Solution {
//public:
//	int depth(TreeNode* root) {
//		return root ? max(depth(root->left), depth(root->right)) + 1 : 0;
//	}
//	bool isBalanced(TreeNode* root) {
//		return root ? abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right) : 1;
//	}

//dfs bottom up solution O(n)

/*class solution {
public:
	int dfsHeight(TreeNode *root) {
		if (root == NULL) return 0;

		int leftHeight = dfsHeight(root->left);
		if (leftHeight == -1) return -1;
		int rightHeight = dfsHeight(root->right);
		if (rightHeight == -1) return -1;

		if (abs(leftHeight - rightHeight) > 1)  return -1;
		return max(leftHeight, rightHeight) + 1;
	}
	bool isBalanced(TreeNode *root) {
		return dfsHeight(root) != -1;
	}
}*/