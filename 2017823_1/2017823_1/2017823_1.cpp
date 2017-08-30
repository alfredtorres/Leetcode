// 2017823_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void ConvertStr(char *str, char* output){
	int length = 0;
	bool m_true = true;
	for (int i = 0; str[i] != '\0'; i++)
		length++;
	if (length > 20){
		cout << "ERROR!";
		m_true = false;
	}	
	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= '0'&&str[i] <= '9') || (str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z'))
			continue;
		else
		{
			cout << "ERROR!";
			m_true = false;
		}
	}
	if (m_true)
	{
		int j = 0;
		for (int i = 0; str[i] != '\0'; i = i + 2){
			output[j++] = str[i];
		}
		output[j] = '\0';
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[100];
	char output[100];
	cin >> str; 
	ConvertStr(str, output);
	for (int i = 0; output[i] != '\0'; i++){
		cout << output[i];
	}
	return 0;
}

