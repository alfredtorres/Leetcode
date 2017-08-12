// NumbersOf1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<bitset>
using namespace std;
using std::bitset;
int NumbersOf1(int num)
{
	int count = 0;
	int temp = 1;
	while (temp)
	{
		if (num & temp)
			count++;
		temp = temp << 1;
	}
	return count;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a1 = 10;
	int a2 = -10;
	int a3 = 0;
	int count1 = NumbersOf1(a1);
	int count2 = NumbersOf1(a2);
	int count3 = NumbersOf1(a3);
	bitset<32> bitvec1(a1); 
	bitset<32> bitvec2(a2);
	bitset<32> bitvec3(a3);
	cout << bitvec1 << endl;
	cout << count1 << endl;
	cout << bitvec2 << endl;
	cout << count2 << endl;
	cout << bitvec3 << endl;
	cout << count3 << endl;
	return 0;
}

