#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {

		/*
		int left = 0;
		int right = nums.size() - 1;

		while (left < right)
		{
			int mid = (left + right) >> 1;

			if (nums[mid] > nums[right]) left = mid + 1;
			else if (nums[mid] < nums[right]) right = mid;
			else right--;
		}
		
		if (left == 0)
		{
			int m = 0;
			int n = nums.size() - 1;
			while (m < n)
			{
				int mid = (m + n) >> 1;
				
				if (nums[mid] > target) n = mid - 1;
				else
					m = mid;
			}
			
			if (nums[m] == target)
				return m;
		}
		else 
		{
			if (nums[0] <= target <= nums[left-1])
			{
				int m = 0;
				int n = left - 1;
				while (m < n)
				{
					int mid = (m + n) >> 1;
					if (nums[mid] > target) n = mid - 1;
					else 
						m = mid;
				}

				if (nums[m] == target)
					return m;
			}
		
			if (nums[left] <= target <= nums[nums.size()])
			{
				int m = left;
				int n = nums.size() - 1;
				while (m < n)
				{
					int mid = (m + n) >> 1;
					if (nums[mid] > target) n = mid - 1;
					else 
						m = mid;
				}

				if (nums[m] == target)
					return m;
			}
		}
		*/
	
	int left = 0;
	int right = nums.size() - 1;

	while (left != right) 
	{
		int mid = left + (right - left)/2;
		if (target == nums[mid])
			return mid;
		if (nums[left] <= nums[mid])
		{
			if (nums[left] <= target && target < nums[mid])
				right = mid - 1;
			else 
				left = mid + 1;
		}
		else
		{
			if (nums[right] >= target && target > nums[mid])
				left = mid + 1;
			else
				right = mid - 1; 
		}
	}
	
	if (nums[left] == target)
		return left;
	
	return -1;
	}
};

int main()
{	
	//int a[] = {4, 5, 6, 7, 0, 1, 2};
	int a[] = {5, 1, 3};
	vector<int> vec(a, a+3);

	Solution S;
	int target;
	while (cin>>target)
		cout<<S.search(vec, target)<<endl;

	return 0;
}
