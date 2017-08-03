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
/*
�����Ԫ��һ���������
û�н��иĽ�
*/
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
/*
����СԪ���Ƶ�������ǰ
���иĽ�
*/
void BubbleSort1(int* a, int length)
{
	for (int i = 0; i < length; i++)
	{
		bool isSorted = true;
		for (int j = length - 1; j>i; j--)
		{
			if (*(a + j) < *(a + j - 1))
			{
				int temp = *(a + j - 1);
				*(a + j - 1) = *(a + j);
				*(a + j) = temp;
				isSorted = false;
			}
		}
		if (isSorted) return;
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
	BubbleSort1(a, length);
	cout << "ѡ����������飺" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

