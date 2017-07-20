// GetDuplicate.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//������д������ɺ�������,������ı������������Ѱ��
	//���ֲ��ң���N����Ϊ�����֣�ͳ��1~N/2   N/2~N�������ֵģ�counting
	//����ΪN+1�����������������1~N
	// ����:
	//        numbers:     һ����������
	//        length:      ����ĳ���
	// ����ֵ:             
	//        int  - (���) �����е�һ���ظ�������
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
	cout << "�ظ�������Ϊ��" << result;
	return 0;
}

