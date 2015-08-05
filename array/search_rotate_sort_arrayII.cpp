#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {

	
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
				if (nums[left] >= target && target > nums[mid])
					right = mid;
				else
					left = mid + 1; 
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
	vector<int> vec(a, a+7);

	Solution S;
	int target = 8;
	//while (cin>>target)
		cout<<S.search(vec, target)<<endl;

	return 0;
}
