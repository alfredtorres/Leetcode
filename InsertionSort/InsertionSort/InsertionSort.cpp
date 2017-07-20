// InsertionSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

/*插入排序
使用递归的思想
将A[i]插入到A[0]~A[i-1]中
*/
void InsertionSort(int* array,int length)
{
	int target;
	for (int i = 1; i < length; i++)
	{
		target = *(array + i);
		int j = 0;
		while ( target> *(array + j) && j < i )
		{
			j++;
		}
		if (j<i)
		{
			for (int k = i; k>j; k--)
			{
				*(array + k) = *(array + k - 1);
			}
			*(array + j) = target;
		}
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
	InsertionSort(a, length);
	cout << "选择排序后数组：" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	
	return 0;
}

