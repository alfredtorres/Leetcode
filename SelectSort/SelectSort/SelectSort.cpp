// SelectSort.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "�������鳤�ȣ�" << endl;
	cin >> length;
	cout << "�������ݣ�" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> a[i];
	}
	cout << endl;
	SelectSort(a, length);
	cout << "ѡ����������飺" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}


