// StackPushPop.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<stack>
#include<time.h>
using namespace std;
bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	stack<int> stackpush;
	int length = pushV.size();
	int i = 0, j = 0;
	bool result = true;
	while (i<length||j<length)
	{
		if (stackpush.empty())
		{
			stackpush.push(pushV[i++]);
		}
		while (stackpush.top() != popV[j] && i<=length)
			stackpush.push(pushV[i++]);
		if (i > length && stackpush.top() != popV[j])//i == length && stackpush.top() != popV[j]这样就是错的。。
			return false;
		if (stackpush.top() == popV[j])
		{
			stackpush.pop();
			j++;
		}
	}
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> pushV = { 1, 2, 3, 4, 5 };
	vector<int> popV = { 4, 3, 5, 1, 2 };
	clock_t start, end;
	double duration;
	start = clock();
	bool result = IsPopOrder(pushV, popV);
	end = clock();
	duration = double(end - start) / CLOCKS_PER_SEC;
	return 0;
}

