// HighestGrade_2016HW.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
#define max(x,y) (x)>(y)?(x):(y)
int _tmain(int argc, _TCHAR* argv[])
{
	int N, M;
	vector<int> array;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		array.push_back(temp);
	}
	vector<char> str;
	vector<int> start, end;
	for (int i = 0; i < M; i++)
	{
		char s;
		int temp1, temp2;
		cin >> s >> temp1 >> temp2;
		str.push_back(s);
		start.push_back(temp1);
		end.push_back(temp2);		
	}
	for (int i = 0; i < M; i++)
	{
		if (str[i] == 'Q')//����start-end������ֵ
		{
			int result = array[start[i] - 1];
			for (int j = start[i] - 1; j < end[i]; j++)
			{
				result = max(result, array[j]);
			}
			cout << result << endl;
		}
		if (str[i] == 'U')//��start�ϵ�����Ϊend
		{
			array[start[i] - 1] = end[i];
		}
	}
	return 0;
}

