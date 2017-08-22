// Baidu2017_1BuyHat.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<set>
#include<iostream>
#include<functional>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	set<int,greater<int>> smallest3;
	int n;
	int result;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (smallest3.size() != 3)
			smallest3.insert(temp);
		else
		{
			set<int>::iterator min3 = smallest3.begin();
			if (temp < *(min3))
			{
				smallest3.insert(temp);
				if(smallest3.size() > 3)
					smallest3.erase(min3);
			}
		}

	}
	if (smallest3.size() < 3)
		result = -1;
	else
		result = *(smallest3.begin());
	cout << result;
	return 0;
}

