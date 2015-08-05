#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target)
	{
		//vector<int> result;

		int left = 0;
		int right = nums.size() - 1;
		int mid;

		while (left < right)
		{
			mid = (left + right) >> 1;
			
			if (nums[mid] > target)	
				right = mid - 1;
			else if (nums[mid] < target)
				left = mid + 1;
			else
				break;
		}
	
		if (nums[left] == target)
			return left;
		if (nums[left] > target)
		{ 
			if(left != 0)
				return left - 1;
			else
				return 0;
		}
		else
			return left + 1;	
	}
};

int main()
{
	//int a[] = {5, 7, 7, 8, 8, 10};
	int a[] = {1, 3};
	vector<int> vec(a, a+2);
	
	
	Solution S;
	int target;
	
	while (cin>>target)
		cout<<S.searchInsert(vec, target)<<endl;

	//cout<<res[0]<<" "<<res[1]<<endl;
	
	return 0;
}
