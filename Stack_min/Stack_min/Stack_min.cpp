// Stack_min.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stack>
using namespace std;
class Solution {
public:
	stack<int> StackData, StackMin;
	void push(int value) {
		StackData.push(value);
		if (StackMin.empty())
			StackMin.push(value);
		else{
			if (top()<value)
				StackMin.push(top());
			else
				StackMin.push(value);
		}
	}
	void pop() {
		StackData.pop();
		StackMin.pop();
	}
	int top() {
		return StackMin.top();
	}
	int min() {
		return StackMin.top();
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

