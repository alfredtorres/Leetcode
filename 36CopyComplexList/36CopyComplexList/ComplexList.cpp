#include"stdafx.h"
#include<cstdio>
#include"ComplexList.h"

ComplexListNode* CreateNode(int value)
{
	ComplexListNode* pNode = new ComplexListNode();
	pNode->val = value;
	pNode->next = nullptr;
	pNode->random = nullptr;
	return pNode;
}
void BuildNodes(ComplexListNode* Node, ComplexListNode* Next, ComplexListNode* random)
{
	if (Node != nullptr)
	{
		Node->next = Next;
		Node->random = random;
	}
}
void PrintList(ComplexListNode* Head)
{
	ComplexListNode* pNode = Head;
	while (pNode != nullptr)
	{
		printf("The value of this node is: %d.\n", pNode->val);

		if (pNode->random != nullptr)
			printf("The value of its sibling is: %d.\n", pNode->random->val);
		else
			printf("This node does not have a sibling.\n");

		printf("\n");

		pNode = pNode->next;
	}
}
