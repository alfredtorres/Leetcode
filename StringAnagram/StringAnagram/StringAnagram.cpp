// StringAnagram.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
bool isStringAnagram(string str1, string str2)
{
	int HashTable[256] = {};
	int i = 0;
	while (str1[i] != '\0')
	{
		HashTable[str1[i]]++;
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		HashTable[str2[i]]--;
		i++;
	}
	i = 0;
	while (i < 256)
	{
		if (HashTable[i] != 0)
			return false;
		i++;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str1 = "evil";
	string str2 = "dive";
	bool result = isStringAnagram(str1, str2);
	cout << result << endl;
	return 0;
}

