#include "solution.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> A = { 1, 3, 5, 6 };
	Solution s;
	std::cout << s.searchInsert(A, 5) << std::endl;
	std::cout << s.searchInsert(A, 2) << std::endl;
	std::cout << s.searchInsert(A, 7) << std::endl;
	std::cout << s.searchInsert(A, 0) << std::endl;
	return 0;
}