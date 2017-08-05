// StringErase_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
string EarseString1FromString2(string str1, string str2)
{
	int HashTable[256] = {};
	int i = 0;
	while (str2[i] != '\0')
	{
		HashTable[str2[i]]++;
		i++;
	}
	i = 0;
	while (str1[i] != '\0')
	{
		if (HashTable[str1[i]] > 0)
			str1 = str1.erase(i, 1);
		i++;
	}
	return str1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	string str1 = "We are students.";
	string str2 = "aeiou";
	cout << str1 << endl;
	cout << str2 << endl;
	string result = EarseString1FromString2(str1, str2);
	cout << result << endl;
	return 0;
}

