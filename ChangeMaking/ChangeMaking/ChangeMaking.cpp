// ChangeMaking.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "�ܽ�";
	cin >> N;
	cout << "��ͬ��ֵ��Ӳ����������";
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
	cout << "��������Ӳ��������" + F[N] << endl;
	cout << "���õ�Ӳ�ҷֱ�Ϊ��" << endl;
	return 0;
}

