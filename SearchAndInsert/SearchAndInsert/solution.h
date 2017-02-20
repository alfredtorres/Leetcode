class Solution {
public:
	int searchInsert(int* nums, int numsSize, int target) {
		int i = 0;
		while (i<numsSize)
		{
			if (nums[i]<target)
				i++;
			else
				break;
		}
		return i;
	}
};

