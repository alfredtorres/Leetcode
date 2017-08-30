// 2017823_3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<math.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int input_x, output_x;
	//long long num;
	string str;
	long long temp = 0;;
	cin >> input_x >> output_x >> str;
	char reslut[100];
	int str_length = str.size();
	//先把input_x转化为10进制
	for (int i = 0; str[i] != '\0'; i++)
	{
		temp = temp + (str[i] - '0')*pow(input_x, str_length - i - 1);
	}
	int c, m = 0, s[100];
	while (temp != 0)
	{
		c = temp%output_x;
		temp = temp / output_x;
		m++;
		s[m] = c;
	}
	int j = 0;
	for (int k = m; k >= 1; k--)
	{
		if (s[k] < 10)
			cout << s[k];
		else if (s[k] < 36 )
			cout << (char)(s[k] + 87);
		else
			cout << (char)(s[k] + 29);
	}
	return 0;
}
int input_x, output_x;
long long num;
long long temp = 0;;
string str;
cin >> input_x >> output_x >> str;

char reslut[100];
int str_length = str.size();
//先把input_x转化为10进制
for (int i = 0; str[i] != '\0'; i++)
{
	if (str[i] >= '0'&&str[i] <= '9')
		temp = temp + str[i] * pow(input_x, str_length - i - 1);
	if (str[i] >= 'a'&&str[i] <= 'z')
		temp = temp + (str[i] - 55 + 10)*pow(input_x, str_length - i - 1);
	if (str[i] >= 'A'&&str[i] <= 'Z')
		temp = temp + (str[i] - '0')*pow(input_x, str_length - i - 1);
}
int c, m = 0, s[100];
while (temp != 0)
{
	c = temp%output_x;
	temp = temp / output_x;
	m++;
	s[m] = c;
}
int j = 0;
for (int k = m; k >= 1; k--)
{
	if (s[k] < 10)
		cout << s[k];
	else if (s[k] < 36)
		cout << (char)(s[k] + 87);
	else
		cout << (char)(s[k] + 29);
}
return 0;
