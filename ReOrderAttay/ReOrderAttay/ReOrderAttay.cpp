// ReOrderAttay.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<time.h>
using namespace std;
void reOrderArray(vector<int> &array)
{
	int end = array[array.size() - 1];
	for (int i = 0; i<array.size(); i++)
	{
		int temp = array[i];
		if (array[i] % 2 == 0)
		{
			array.push_back(array[i]);
			array.erase(array.begin() + i);
			i--;
		}
		if (temp == end) break;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	//vector<int> array = { 2, 4, 6, 1, 3, 5, 7 };
	vector<int> array = { 2 };
	clock_t start, finish;
	double totaltime;
	start = clock();
	reOrderArray(array);
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << "   ";
	}
	
	return 0;
}

