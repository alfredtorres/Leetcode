// MoreHalfNums.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
using namespace std;
void QuickSort(vector<int> numbers, int start, int end){
	if (start<end){
		int i = start, j = end;
		int k = numbers[i];
		while (i<j){
			while (i<j&&numbers[j]>k)
				j--;
			if (i<j)
				numbers[i++] = numbers[j];
			while (i<j&&numbers[i]<k)
				i++;
			if (i<j)
				numbers[j--] = numbers[i];
		}
		numbers[i] = k;
		QuickSort(numbers, start, i - 1);
		QuickSort(numbers, i + 1, end);
	}
}
int MoreThanHalfNum_Solution(vector<int> numbers) {
	int length = numbers.size();
	int result = 0;
	if (length <= 0)
		return 0;
	else{
		QuickSort(numbers, 0, length - 1);
		result = numbers[length / 2];
		int nums = 0;
		for (int i = 0; i < length; i++)
		{
			if (numbers[i] == result)
				nums++;
		}
		if (nums<=length / 2)
			result = 0;
	}
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = { 4,2,1,4,2,4 };
	int num = MoreThanHalfNum_Solution(vec);
	return 0;
}

