// CoinRow.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*��ֵ�������
��һ��N��Ӳ����ѡ���ܺ�����һ�飬Ҫ�󻥲�����
*/
#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
#define max(x,y) (x)>(y)?(x):(y)
int _tmain(int argc, _TCHAR* argv[])
{
	int N;
	cout << "Ӳ��������";
	cin >> N;
	vector<int> Coin;//������еı�ֵ
	vector<int> F;//������е����ֵ
	vector<int> index;//���������ֵ���±�
	cout << "ÿ��Ӳ�ҵĽ�";
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
	cout << "����ܽ��Ϊ��"<<F[N] << endl;
	cout << "���������Ӧ�ı�ֵΪ��" << endl;
	for (int i = 0; i < index.size(); i++)
	{
		cout << Coin[index[i] - 1] << endl;
	}

	return 0;
}

