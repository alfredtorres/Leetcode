// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void Merge(int* b, int length1, int* c, int length2, int* a,int length3 )
{
	int i = 0, j = 0, k = 0;
	while (i<length1&&j<length2)
	{
		if (*(b + i) < *(c + j))
		{
			*(a + k) = *(b + i);
			i++;
			k++;
		}
		else
		{
			*(a + k) = *(c + j);
			j++;
			k++;
		}
	}
	if (i == length1)
	{
		while (j<length2)
		{
			*(a + k) = *(c + j);
			j++;
			k++;
		}
	}
	else
	{
		while (i<length1)
		{
			*(a + k) = *(b + i);
			i++;
			k++;
		}
	}
}
void MergeSort(int* a, int length)
{
	int* b = new int[length];
	int* c = new int[length];
	if (length > 1)
	{
		int j = 0;
		for (int i = 0; i < length / 2; i++)
		{
			b[j] = a[i];
			j++;
		}
		j = 0;
		for (int i = length / 2 ; i < length; i++)
		{
			*(c + j) = *(a + i);
			j++;
		}
		int length1 = length / 2;
		int length2 = length - length / 2;
		MergeSort(b, length1);
		MergeSort(c, length2);
		Merge(b, length1, c, length2, a, length);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 8, 3, 2, 9, 7, 1, 5, 4 };
	int length = sizeof(a) / sizeof(a[0]);
	MergeSort(a, length);
	cout << "选择排序后数组：" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

