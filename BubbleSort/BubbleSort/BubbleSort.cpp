// BubbleSort.cpp : 定义控制台应用程序的入口点。
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
将最大元素一到数组最后
没有进行改进
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
将最小元素移到数组最前
进行改进
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
	cout << "原数组：" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	BubbleSort1(a, length);
	cout << "选择排序后数组：" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

