#include <vector>
using namespace std;
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		int length = nums.size();
		int result;
		int first = INT_MIN;//�����������ı�����int�͵���Сֵ
		int second = INT_MIN;
		int third = INT_MIN;
		int sum = 0;//���������ظ���
		int bottom = 0;//���Ƿ��е���INT_MIN����
		if (length == 1)
			result = nums[0];
		else if (length==2)
			result = nums[0] > nums[1] ? nums[0] : nums[1];
		else
		{
			for (size_t i = 0; i < length; i++)
			{
				if (nums[i] == INT_MIN)
					bottom = 1;
				if (nums[i] == first || nums[i] == second || nums[i] == third)
				{
					continue;
				}					
				if (nums[i]>first)
				{
					third = second;
					second = first;					
					first = nums[i];
					sum++;
				}
				else if (nums[i]>second)
				{
					third = second;
					second = nums[i];
					sum++;
				}
				else if (nums[i]>third)
				{
					third = nums[i];
					sum++;
				}
			}
			if (sum+bottom < 3)
			{
				result = first;
			}
			else
			{
				result = third;
			}
		}
		return result;
	}
};