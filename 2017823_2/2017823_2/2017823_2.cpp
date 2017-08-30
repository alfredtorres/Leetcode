// 2017823_2.cpp : 定义控制台应用程序的入口点。
//
/*题目描述
给定一个整数，给出消除重复数字以后最大的整数
输入描述：
正整数，注意考虑长整数
输出描述
消除重复数字后的最大整数
示例1
输入
423234
输出
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

