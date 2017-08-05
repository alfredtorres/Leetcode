// FirstNotRepeatingChar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
char FirstNotRepeatingChar(string str)
{
	int HashTable[256] = {};
	int i = 0;
	while (str[i]!='\0')
	{
		HashTable[(str[i])]++;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (HashTable[(str[i])] == 1)
			return str[i];
		i++;
	}
	return '\0';
}
int _tmain(int argc, _TCHAR* argv[])
{
	string  str1 = "a";
	string  str2 = "aabccdbd";
	string  str3 = "abcdefg";
	string  str4 = "";
	char c1 = FirstNotRepeatingChar(str1);
	char c2 = FirstNotRepeatingChar(str2);
	char c3 = FirstNotRepeatingChar(str3);
	char c4 = FirstNotRepeatingChar(str4);
	cout << str1 << endl;
	cout << c1 << endl;
	cout << str2 << endl;
	cout << c2 << endl;
	cout << str3 << endl;
	cout << c3 << endl;
	cout << str4 << endl;
	cout << c4 << endl;
	return 0;
}

