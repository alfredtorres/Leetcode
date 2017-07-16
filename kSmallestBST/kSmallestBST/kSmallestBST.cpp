// kSmallestBST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};
class Solution {
public:
	vector<int> inorder;
	int kthSmallest(TreeNode* root, int k) {
		inOrder(root);
		return inorder[k - 1];
	}
	void inOrder(TreeNode* root)
	{
		if (root != NULL)
		{
			inOrder(root->left);
			inorder.push_back(root->val);
			inOrder(root->right);
		}
	}
};
