// Isarithmeticarray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
void quicksort(int* array, int start, int end){
	if (start<end){
		int i = start, j = end;
		int k = array[start];
		while (i<j){
			while (i<j&&array[j]>k){
				j--;
			}
			if (i<j)
				array[i++] = array[j];
			while (i<j&&array[i]<k){
				i++;
			}
			if (i<j)
				array[j--] = array[i];
		}
		array[i] = k;
		quicksort(array, start, i - 1);
		quicksort(array, i + 1, end);
	}
}
int main(){
	int length;
	int array[50];
	string result;
	cin >> length;
	for (int i = 0; i<length; i++){
		cin >> array[i];
	}
	quicksort(array, 0, length - 1);
	int j = 1;
	int de = array[1] - array[0];
	while (j<length - 1){
		if (array[j] - array[j - 1] != de){
			result = "Impossible";
			break;
		}
		j++;
	}
	result = "Possible";
	cout << result;
	return 0;
}

