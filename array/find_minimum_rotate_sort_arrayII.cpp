#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;

		while (left < right)
		{
			int mid = (left + right) >> 1;

			if (nums[mid] > nums[right]) left = mid + 1;
			else if (nums[mid] < nums[right]) right = mid;
			else right--;
		}

		return nums[left];
	}
};

int main()
{
	int a[] = {1, 3, 3, 3};
	//int a[] = {3, 1, 3, 3, 3};
	//int a[] = {1, 1};
	
	vector<int> vec(a, a+4);
	Solution S;
	
	cout<<S.findMin(vec)<<endl;
	return 0;
}
