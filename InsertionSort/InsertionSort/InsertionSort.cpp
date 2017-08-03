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
/*直接插入排序
上面的代码复杂，为了减少移动次数，应该从右往左扫描表
*/
void InsertionSort2(int* array, int length)
{
	for (int i = 1; i < length; i++)
	{
		int tmp = *(array + i);
		int j = i - 1;
		while (j >= 0 && tmp < *(array + j))
		{
			*(array + j + 1) = *(array + j);
			j--;
		}
		*(array + j + 1) = tmp;
	}
}
/*折半插入排序
将表中寻找的过程，用二分查找代替，加快查找的速度
*/
void InsertionSortMid(int* array, int length)
{
	int i, j, start, mid, end;
	for (i = 1; i < length; i++)
	{
		int temp = *(array + i);
		start = 0;
		end = i - 1;
		while (start<=end)
		{
			mid = (start + end) / 2;
			if (*(array + mid) < temp)
				start = mid + 1;
			if (*(array + mid) > temp)
				end = mid - 1;
		}
		for (j = i - 1; j >= end + 1; j--)
			*(array + j + 1) = *(array + j);
		*(array + end + 1) = temp;
	}
}
void ShellSort(int* array, int length)
{
	int gap[] = { 4, 1 };
	int i, j, k;
	for ( i = 0; i < 2; i++)
	{
		int step = gap[i];
		for ( j = step; j < length; j++)
		{
			int temp = *(array + j);
			k = j - 1;
			while (k >= 0 && temp < *(array + k))
			{
				*(array + k + 1) = *(array + k);
				k--;
			}
			*(array + k + 1) = temp;
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
	ShellSort(a, length);
	cout << "选择排序后数组：" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	
	return 0;
}

