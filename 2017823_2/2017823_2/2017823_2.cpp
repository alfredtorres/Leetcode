// 2017823_2.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*��Ŀ����
����һ�����������������ظ������Ժ���������
����������
��������ע�⿼�ǳ�����
�������
�����ظ����ֺ���������
ʾ��1
����
423234
���
432*/

#include "stdafx.h"
#include"stdio.h"
#include<iostream>
#include"math.h"
#include<string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	long long num;
	cin >> num;
	long long output = 0;
	string str = to_string(num);
	int result[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int hashtable[10] = {};
	for (int i = 0; str[i] != '\0'; i++)
	{
		hashtable[str[i]-'0'] = 1;
	}
	int j = 0;
	int length = 0;
	for (int i = 9; i >= 0; i--)
	{
		if (hashtable[i] == 1)
		{
			length++;
			result[j++] = i;
		}
	}
	for (int i = 0; i < length; i++)
	{
		output = output + result[i] * pow(10, length - i - 1);
	}
	cout << output;
	return 0;
}

