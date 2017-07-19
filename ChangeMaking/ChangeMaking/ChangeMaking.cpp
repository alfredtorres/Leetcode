// ChangeMaking.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
#define min(x,y) (x)<(y)?(x):(y)

int _tmain(int argc, _TCHAR* argv[])
{
	int N, M;
	vector<int> Coin;
	vector<int> F;
	cout << "总金额：";
	cin >> N;
	cout << "不同面值的硬币种类数：";
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		Coin.push_back(temp);
	}
	vector<int> coinValue;
	int usedCoin;
	F.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		int temp;
		int k;
		for (int j = 0; j < M; j++)
		{
			if (Coin[j] <= i)
			{
				temp = F[i - Coin[j]];
				k = j;
			}
			break;
		}
		for (int j = k+1; j < M; j++)
		{
			if (Coin[j] <= i)
			{
				temp = min(temp, F[i - Coin[j]]);
				usedCoin = Coin[j];
			}
		}
		F.push_back(temp + 1);
		coinValue.push_back(usedCoin);
	}
	cout << "所用最少硬币数量：" + F[N] << endl;
	cout << "所用的硬币分别为：" << endl;
	return 0;
}

