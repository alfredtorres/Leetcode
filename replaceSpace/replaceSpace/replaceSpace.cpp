// replaceSpace.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
using namespace std;
void replaceSpace(char *str, int length)
{
	if (str == nullptr || length < 0)
		return;
	int numofspace = 0;
	int originlength = 0;
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		originlength++;
		if (*(str + i)==0x20)
			numofspace++;
	}
	int newlength = originlength + 2 * numofspace;
	if (newlength > length)
		return;
	while (originlength >= 0 && originlength < newlength)
	{
		if (*(str + originlength) == 0x20)
		{
			*(str + newlength--) = '0';
			*(str + newlength--) = '2';
			*(str + newlength--) = '%';
		}
		else
		{
			*(str + newlength--) = *(str + originlength);
		}
		originlength--;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	char str[50] = "We Are Happy.";
	int length = 50;
	for (int i = 0; str[i] != '\0'; i++)
		cout << str[i];
	cout << endl;
	replaceSpace(str, length);
	for (int i = 0; str[i] != '\0'; i++)
		cout << str[i];
	return 0;
}

