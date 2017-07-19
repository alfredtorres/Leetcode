// LinklistSwap2Nodes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
typedef struct LNode
{
	int data;
	struct LNode *next;
}Linklist;
class Solution{
public:
	Linklist* Swap2Nodes(Linklist *node, int c1, int c2)
	{
		Linklist *dump = new Linklist();
		dump->next = node;
		Linklist *pre = dump, *cur = dump, *p1 = NULL, *p2 = NULL;
		while (cur->next != NULL)
		{
			if (cur->next->data == c1 || cur->next->data == c2)
			{
				if (!p1)
				{
					p1 = cur->next;
					pre = cur;
				}
				else
				{
					Linklist *t = cur->next->next;
					p2 = cur->next;
					pre->next = cur;
					if (cur == p1)//如果相邻？
					{
						p2->next = p1;
						p1->next = t;
					}
					else
					{
						p2->next = p1->next;
						cur->next = p1;
						p1->next = t;
					}
					return dump->next;
				}
			}
			cur = cur->next;
		}
		return dump->next;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

