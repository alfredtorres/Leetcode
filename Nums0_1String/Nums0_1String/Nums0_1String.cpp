// Nums0_1String.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string>
#include<iostream>
#define max(x,y) (x)>(y)?(x):(y)
using namespace std;
int numsof01array(string str)
{
	//���ȼ���str�ĳ���
	int strlen = str.size();
	//while (str[strlen] != '/0')
	//	strlen++;
	//��str������ͺ�һ���ַ���һ�����
	int xor[50];
	for (int i = 0; i < strlen-1; i++)
	{
		xor[i] = str[i] ^ str[i + 1];
	}
	//ͳ��������������1�ĳ���
	int maxlen = 0, temp = 0;
	for (int i = 0; i < strlen - 1; i++)
	{
		if (xor[i] == 0)
		{
			maxlen = max(maxlen, temp);
			temp = 0;
		}
		if (xor[i] == 1)
		{
			temp++;
		}
	}
	maxlen = max(maxlen, temp);
	return maxlen + 1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string str = { 1, 0, 1, 0, 1, 0, 1};
	int result = numsof01array(str);
	return 0;
}

