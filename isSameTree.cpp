#include<iostream>
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL) return (q == NULL);
		if (q == NULL) return (p == NULL);
		if (q->val != p->val) return false;
		if (p->left == NULL && q->left == NULL && p->right == NULL && q->right == NULL)
			return (p->val == q->val);
		return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
	}
};

//one line solution
//bool isSameTree(TreeNode* p, TreeNode* q)
//{
//	return (p == NULL && q == NULL)
//		|| (p != NULL && q != NULL && p->val == q->val)
//		&& isSameTree(p->left, q->left
//			&& isSameTree(p->right, q->right);
//}