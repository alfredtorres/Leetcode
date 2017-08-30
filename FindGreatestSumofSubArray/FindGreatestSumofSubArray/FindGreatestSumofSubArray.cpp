// FindGreatestSumofSubArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
using namespace std;
#define max(x,y) (x)>(y)?(x):(y)
int FindGreatestSumofSubArray(vector<int> array)
{
	int length = array.size();
	vector<int> sum;
	sum.push_back(array[0]);
	int result = sum[0];
	for (int i = 1; i < length; i++)
	{
		if (sum[i-1] <= 0)
		{
			sum.push_back(array[i]);
		}
		else
		{
			sum.push_back(sum[i - 1] + array[i]);
		}
		result = max(sum[i], result);
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> array = { 6, -3, -2, 7, -15, 1, 2, 2 };
	int result = FindGreatestSumofSubArray(array);
	return 0;
}

