// DoubleCoreQuestion.cpp : 定义控制台应用程序的入口点。
//
/*双核问题：一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，
假设已知CPU的每个核1秒可以处理1kb，每个核同时只能处理一项任务。
n个任务可以按照任意顺序放入CPU进行处理，现在需要设计一个方案让CPU处理完这批任务所需的时间最少，求这个最小的时间。 
输入描述:输入包括两行：
第一行为整数n(1 ≤ n ≤ 50)
第二行为n个整数length[i](1024 ≤ length[i] ≤ 4194304)，表示每个任务的长度为length[i]kb，每个数均为1024的倍数。
输入：5
3072 3072 7168 3072 1024    */
#include "stdafx.h"
#include<iostream>
using namespace std;
#define V 50
#define max(x,y) (x)>(y)?(x):(y)
long int weight[V];
long int F[V][V];

int _tmain(int argc, _TCHAR* argv[])
{
	int N, M;
	int sum = 0;
	cout << "任务数N：";
	cin >> N;
	cout << "每个任务的长度：";
	for (int i = 1; i <= N; i++)
	{
		cin >> weight[i];
		weight[i] = weight[i] / 1024;
		sum = sum + weight[i];
	}
	M = sum / 2;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j >= weight[i])
				F[i][j] = max(F[i - 1][j], F[i - 1][j - weight[i]] + weight[i]);
			else
				F[i][j] = F[i - 1][j];
		}
	}
	long result = max(F[N][M], sum - F[N][M]);
	cout << result * 1024 << endl;
	return 0;
}

