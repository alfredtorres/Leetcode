// GetDuplicate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int count(const int numbers[], int length, int start, int end)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start&&numbers[i] <= end)
			count++;
	}
	return count;
}
int GetDuplicate(const int numbers[], int length)
{
	//以下填写代码完成函数功能,不允许改变数组内容完成寻找
	//二分查找，将N划分为两部分，统计1~N/2   N/2~N两个部分的，counting
	//长度为N+1的数组里，所有数字在1~N
	// 参数:
	//        numbers:     一个整数数组
	//        length:      数组的长度
	// 返回值:             
	//        int  - (输出) 数组中的一个重复的数字
	int start = 1, end = length - 1;
	int mid, count1, count2;
	while (start < end)
	{
		mid = (start + end) / 2;
		count1 = count(numbers, length, start, mid);
		count2 = count(numbers, length, mid + 1, end);
		if (count1>(mid - start + 1))
		{
			end = mid;
		}
		if (count2 > (end - mid ))
		{
			start = mid;
		}
	}
	if (start == end)
		return start;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 2, 3, 5, 4, 5, 1, 6, 7 };
	int length = sizeof(a) / (sizeof(a[0]));
	int result = GetDuplicate(a, length);
	cout << "重复的数字为：" << result;
	return 0;
}

