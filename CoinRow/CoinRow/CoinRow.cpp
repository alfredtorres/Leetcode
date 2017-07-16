// CoinRow.cpp : 定义控制台应用程序的入口点。
//
/*币值最大问题
在一堆N个硬币中选出总和最大的一组，要求互不相邻
*/
#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
#define max(x,y) (x)>(y)?(x):(y)
int _tmain(int argc, _TCHAR* argv[])
{
	int N;
	cout << "硬币总数：";
	cin >> N;
	vector<int> Coin;//存放所有的币值
	vector<int> F;//存放所有的最大值
	vector<int> index;//存放组成最大值的下表
	cout << "每个硬币的金额：";
	for (int i = 0; i < N; i++)
	{
		//cin >> Coin[i];
		int m;
		cin >> m;
		Coin.push_back(m);
	}
	F.push_back(0);
	F.push_back(Coin[0]);
	for (int i = 2; i <= N; i++)
	{
		F.push_back( max(F[i - 1], F[i - 2] + Coin[i - 1]));
	}
	for (int i = Coin.size() - 1; i >= 0; i--)
	{
		int temp = F[i];
		if (temp < F[i + 1])
		{
			index.push_back(i + 1);
			temp = F[i + 1] - Coin[i];
			for (int j = 0; j < Coin.size(); j++)
			{
				if (F[j] == temp)
				{
					i = j;
					break;
				}
			}
		}
	}
	cout << "最大总金额为："<<F[N] << endl;
	cout << "组成最大金额对应的币值为：" << endl;
	for (int i = 0; i < index.size(); i++)
	{
		cout << Coin[index[i] - 1] << endl;
	}

	return 0;
}

