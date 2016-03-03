#include<iostream>
using namespace std;
// definition for a binary tree node.
 struct treenode {
     int val;
     treenode *left;
     treenode *right;
     treenode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool hasPathSum(treenode* root, int sum) {
		if (!root) return false;
		if (!(root->left) && !(root->right)) return root->val == sum;
		return (hasPathSum(root->left, sum - root->val)) || (hasPathSum(root->right, sum - root->val));
	}
};