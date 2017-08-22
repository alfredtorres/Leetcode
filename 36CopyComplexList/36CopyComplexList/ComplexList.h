#pragma once
struct ComplexListNode
{
	int val;
	ComplexListNode* next;
	ComplexListNode* random;
};
ComplexListNode* CreateNode(int value);
void BuildNodes(ComplexListNode* Node, ComplexListNode* Next, ComplexListNode* random);
void PrintList(ComplexListNode* Head);