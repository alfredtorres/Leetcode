// SelectSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#define M 50
using namespace std;
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void SelectSort(int *a, int length)
{
	int min;
	for (int i = 0; i < length ; i++)
	{
		min = i;
		for (int j = i + 1; j < length ; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		Swap(a + i, a + min);
		/*int temp = a[i];
		a[i] = a[min];
		a[min] = temp;*/
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*int a[] = { 89, 45, 68, 90, 29, 34, 17 };
	int length = sizeof(a) / sizeof(a[0]);*/
	int length;
	int a[M];
	cout << "输入数组长度：" << endl;
	cin >> length;
	cout << "输入数据：" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> a[i];
	}
	cout << endl;
	SelectSort(a, length);
	cout << "选择排序后数组：" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}


