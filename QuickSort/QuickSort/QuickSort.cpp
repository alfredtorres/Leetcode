// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void QuickSort(int array[], int start, int end);
int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 4, 3, 8, 9, 2, 1, 5, 7, 6 };
	int length = 9;
	int start = 0;
	int end = 9 - 1;
	QuickSort(a, start, end);
	cout << "快速排序结果：" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << a[i] <<endl;
	}
	return 0;
}

void QuickSort(int *array,  int start, int end)
{
	if (start < end)
	{
		int i = start, j = end, x = array[start];
		while (i<j)
		{
			while (i < j&&array[j] > x)
			{
				j--;
			}
			if (i < j)
				array[i++] = array[j];
			while (i<j&&array[i]<x)
			{
				i++;
			}
			if (i < j)
				array[j--] = array[i];
		}
		array[i] = x;
		QuickSort(array, start, i - 1);
		QuickSort(array, i + 1, end);
	}
}
//int Partition(int *data,int length,int start,int end)
//{
//	//返回分裂位置
//	//以第一个元素为中轴，对子数组进行划分
//	if (data == NULL || length < 0 || start<0 || end>length - 1)
//		return -1;	
//	int i = start + 1;
//	int j = end;
//	while (i <= j)
//	{
//		while (data[i]<data[start])
//		{
//			i++;
//		}
//		while (data[j]>data[start])
//		{
//			j--;
//		}
//		if (data[i] != data[j])
//		{
//			int temp = data[j];
//			data[j] = data[i];
//			data[i] = data[j];
//		}
//	}
//	int temp = data[start];
//	data[j] = data[start];
//	data[start] = data[j];
//	return j;
//}
