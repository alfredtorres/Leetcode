// StringErase_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
string EraseRepeatCharacter(string str)
{
	int HashTable[256] = {};
	int i = 0;
	while (str[i] != '\0')
	{	
		if (HashTable[str[i]] == 1)
			str = str.erase(i, 1);
		else
		{
			HashTable[str[i]] = 1;
			i++;
		}
	}
	return str;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "google";
	cout << str << endl;
	cout << EraseRepeatCharacter(str) << endl;
	return 0;
}

