// DoubleCoreQuestion.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*˫�����⣺һ��˫��CPU���������ܹ�ͬʱ�Ĵ�������������n����֪��������������Ҫ����CPU����
������֪CPU��ÿ����1����Դ���1kb��ÿ����ͬʱֻ�ܴ���һ������
n��������԰�������˳�����CPU���д���������Ҫ���һ��������CPU�������������������ʱ�����٣��������С��ʱ�䡣 
��������:����������У�
��һ��Ϊ����n(1 �� n �� 50)
�ڶ���Ϊn������length[i](1024 �� length[i] �� 4194304)����ʾÿ������ĳ���Ϊlength[i]kb��ÿ������Ϊ1024�ı�����
���룺5
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
	cout << "������N��";
	cin >> N;
	cout << "ÿ������ĳ��ȣ�";
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

