// merge2sortedarray.cpp : 定义控制台应用程序的入口点。
//
/*合并两个排序数组
从5、替换空格延伸而来
之后的延伸包括合并两个排序链表
*/
#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
void mergesortarray(vector<int> array1,vector<int> array2)
{
	int length1 = array1.size();
	int length2 = array2.size();
	int newlength = length1 + length2 - 1;
	int i = length1 - 1;
	int j = length2 - 1;
	while (i >= 0 && j >= 0)
	{
		if (array1[i] >= array2[j])
		{
			array1[newlength--] = array1[i--];
		}
		else
		{
			array1[newlength--] = array2[j--];
		}
	}
	while (i >= 0)
		array1[newlength--] = array1[i--];
	while (j >= 0)
		array2[newlength--] = array2[j--];
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> array1 = { 1, 3, 5, 7, 9 };
	vector<int> array2 = { 2,4,6,8 };
	mergesortarray(array1, array2);
	return 0;
}

