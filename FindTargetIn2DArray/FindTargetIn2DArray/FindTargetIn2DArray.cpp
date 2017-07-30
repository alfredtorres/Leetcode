// FindTargetIn2DArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
using namespace std;
bool Find(int target, vector<vector<int> > array) {
	int row = array.size();
	int col = array[0].size();
	int i = 0, j = col - 1;
	while (i < row&&j >= 0)
	{
		if (array[i][j] == target)
			return true;
		if (array[i][j] < target)
			i++;
		else
			j--;
	}
	return false;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int> > array = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	//vector<vector<int> > array = { { 1, 2, 3 }, { 5, 6, 7 }, { 9, 10, 11,} };
	int target = 7;
	bool result = Find(target, array);
	return 0;
}

