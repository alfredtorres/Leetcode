// Nums0_1String.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
#define max(x,y) (x)>(y)?(x):(y)
using namespace std;
int numsof01array(string str)
{
	//首先计算str的长度
	int strlen = str.size();
	//while (str[strlen] != '/0')
	//	strlen++;
	//将str里的数和后一个字符做一次异或
	int xor[50];
	for (int i = 0; i < strlen-1; i++)
	{
		xor[i] = str[i] ^ str[i + 1];
	}
	//统计异或中最长的连续1的长度
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

