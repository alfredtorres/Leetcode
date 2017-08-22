// NetEase812_4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int array[20000];
	int result[20000];
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> array[i];
	}
	if (n % 2 == 0){
		for (int i = 0; i<n / 2; i++){
			result[i] = array[n - 2 * i - 1];
		}
		for (int i = n / 2; i<n; i++){
			result[i] = array[2 * (i - n / 2)];
		}
	}
	else{
		for (int i = 0; i<n / 2 + 1; i++){
			result[i] = array[n - 1 - 2 * i];
		}
		for (int i = n / 2 + 1; i<n; i++){
			result[i] = array[2 * (i - n / 2 - 1) + 1];
		}
	}
	for (int i = 0; i<n; i++)
		cout << result[i] << "";
	return 0;
}

