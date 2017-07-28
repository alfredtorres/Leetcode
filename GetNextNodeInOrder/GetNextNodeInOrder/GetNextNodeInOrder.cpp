// GetNextNodeInOrder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		TreeLinkNode *node = nullptr;
		if (pNode == nullptr)
			return nullptr;
		if (pNode->right != nullptr)
		{
			TreeLinkNode *p_right = pNode->right;
			while (p_right->left != nullptr)
				p_right = p_right->left;
			node = p_right;
		}
		else if (pNode->next != nullptr)
		{
			if (pNode == pNode->next->left)
				node = pNode->next;
			if (pNode == pNode->next->right)
			{
				TreeLinkNode *p_parent = pNode->next;
				while (p_parent->next != nullptr&&p_parent != p_parent->next->left)
					p_parent = p_parent->next;
				if (p_parent->next == nullptr)
					return nullptr;
				else
					node = p_parent->next;
			}
		}
		return node;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

