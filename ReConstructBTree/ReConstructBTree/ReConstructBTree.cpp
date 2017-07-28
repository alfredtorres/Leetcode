// ReConstructBTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include"BinaryTree.h"
using namespace std;
//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//};
int VectorFind(vector<int> num, int target)
{
	int i = 0;
	while (num[i] != target&&i<num.size())
		i++;
	return i;
}
BinaryTreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	BinaryTreeNode *root = new BinaryTreeNode();;
	if (pre.size() >= 1 && vin.size() >= 1)
	{
		int rootval = pre[0];
		root->m_nValue = rootval;
		int index = VectorFind(vin, rootval);
		int leftlength = index;
		int rightlength = vin.size() - index - 1;
		vector<int> pre_left = {}; 
		vector<int> pre_right = {};
		vector<int> vin_left = {};
		vector<int> vin_right = {};
		if (leftlength > 0)
		{
			for (int i = 0; i<leftlength; i++)
			{
				pre_left.push_back(pre[i + 1]);
				vin_left.push_back(vin[i]);
			}
		}
		if (rightlength > 0)
		{
			for (int i = 0; i<rightlength; i++)
			{
				pre_right.push_back(pre[i + index + 1]);
				vin_right.push_back(vin[i + index + 1]);
			}
		}
		if (leftlength>0)
		{
			root->m_pLeft = reConstructBinaryTree(pre_left, vin_left);
		}
		if (rightlength > 0)
		{
			root->m_pRight = reConstructBinaryTree(pre_right, vin_right);
		}
	}
	else
		root = NULL;
	return root;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BinaryTreeNode *result = reConstructBinaryTree(pre, vin);
	//PrintTree(result);
	return 0;
}

