// GetLeastNumbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<set>
#include<vector>
#include<functional>
using namespace std;
vector<int> GetLeastNumbers(vector<int> input, int k)
{
	multiset<int,greater<int>> LeastSet;//定义了一个递减的set
	LeastSet.clear();
	int length = input.size();
	if (length <= 0 || k <= 0)
		return vector<int>();
	vector<int>::const_iterator iter = input.begin();
	for (;iter!=input.end();iter++)
	{
		if (LeastSet.size() < k)
			LeastSet.insert(*iter);
		else
		{
			multiset<int, greater<int>>::const_iterator iterGreatest = LeastSet.begin();
			if (*iter < *(LeastSet.begin()))
			{
				LeastSet.erase(iterGreatest);
				LeastSet.insert(*iter);
			}
		}
	}
	return vector<int>(LeastSet.begin(), LeastSet.end());
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> input = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int k = 4;
	vector<int> output = GetLeastNumbers(input, k);
	return 0;
}

