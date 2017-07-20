// BubbleSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(int* a, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (a[j]>a[j + 1])
				Swap(a + j, a + j + 1);
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 89, 45, 68, 90, 29, 34, 17 };
	int length = sizeof(a) / sizeof(a[0]);
	cout << "ԭ���飺" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	BubbleSort(a, length);
	cout << "ѡ����������飺" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

