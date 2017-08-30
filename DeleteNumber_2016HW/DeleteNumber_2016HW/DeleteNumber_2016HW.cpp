// DeleteNumber_2016HW.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int N;
	while (cin >> N)
	{
		vector<int> array;
		for (int i = 0; i < N; i++)
			array.push_back(i);
		vector<int>::iterator it = array.begin();
		int i = 0;
		while (array.size()>1)
		{
			if ((i + 1) % 3 != 0)
				it++;
			if ((i + 1) % 3 == 0)
				it = array.erase(it);
			i++;
			if (it == array.end())
				it = array.begin();
		}
		if (array.size() == 1)
			cout << array[0];
	}
	return 0;
}

