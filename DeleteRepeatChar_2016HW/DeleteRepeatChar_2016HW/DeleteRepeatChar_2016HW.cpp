// DeleteRepeatChar_2016HW.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char str[100];
	
	while (cin >> str)
	{
		int hashtable[256] = {};
		int j = 0;
		for (int i = 0; str[i]!='\0'; i++)
		{			
			if (hashtable[str[i]] == 0)
			{
				hashtable[str[i]] = 1;
				cout << str[i];
			}
		}
		cout << endl;
	}
	return 0;
}

