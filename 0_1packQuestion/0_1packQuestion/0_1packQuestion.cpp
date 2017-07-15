// 0_1packQuestion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define V 50
unsigned int F[10][V];
unsigned int weight[10];
unsigned int value[10];
#define max(x,y) (x)>(y)?(x):(y)

int _tmain(int argc, _TCHAR* argv[])
{
	int N, M;
	cout << "N:" << endl;
	cin >> N;
	cout << "M:" << endl;
	cin >> M;
	cout << "每件物品的重量和价值:" << endl;
	for (int i = 1; i <= N; i++)
	{
		cin >> weight[i] >> value[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j >= weight[i])
				F[i][j] = max(F[i - 1][j], F[i - 1][j - weight[i]] + value[i]);
			else
				F[i][j] = F[i - 1][j];
		}
	}
	cout << F[N][M] << endl;
	return 0;
}

