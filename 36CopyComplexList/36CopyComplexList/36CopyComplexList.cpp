// 36CopyComplexList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"ComplexList.h"
#include<map>
using namespace std;

ComplexListNode* CopyList(ComplexListNode* pHead, map<ComplexListNode*, ComplexListNode*> &hashTable)
{
	if (pHead == nullptr)
		return nullptr;
	hashTable.insert(make_pair(nullptr, nullptr));
	ComplexListNode* pNode = CreateNode(pHead->val);
	ComplexListNode* temp = pNode;
	hashTable.insert(make_pair(pHead, pNode));
	pHead = pHead->next;
	while (pHead != nullptr)
	{
		ComplexListNode* pCloneNode = CreateNode(pHead->val);
		temp->next = pCloneNode;
		temp = temp->next;
		hashTable.insert(make_pair(pHead, pCloneNode));
		pHead = pHead->next;
	}
	return pNode;
}
void ConnectRandom(ComplexListNode* pHead, ComplexListNode* pNode, map<ComplexListNode*, ComplexListNode*> hashTable)
{
	while (pHead != nullptr)
	{
		pNode->random = hashTable[pHead->random];
		pHead = pHead->next;
		pNode = pNode->next;
	}
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
	map<ComplexListNode*, ComplexListNode*> hashTable;
	ComplexListNode* pNode = CopyList(pHead, hashTable);
	ConnectRandom(pHead, pNode, hashTable);
	return pNode;
}
void Test(const char* testName, ComplexListNode* pHead)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The original list is:\n");
	PrintList(pHead);

	ComplexListNode* pClonedHead = Clone(pHead);

	printf("The cloned list is:\n");
	PrintList(pClonedHead);
}
int _tmain(int argc, _TCHAR* argv[])
{
	ComplexListNode* pNode1 = CreateNode(1);
	ComplexListNode* pNode2 = CreateNode(2);
	ComplexListNode* pNode3 = CreateNode(3);
	ComplexListNode* pNode4 = CreateNode(4);
	ComplexListNode* pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, pNode3);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, nullptr);
	BuildNodes(pNode4, pNode5, pNode2);
	Test("Test1", pNode1);
	return 0;
}

