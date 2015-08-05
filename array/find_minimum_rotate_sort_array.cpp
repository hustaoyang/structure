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
			else right = mid;
		}

		return nums[right];
	}
};

int main()
{
	int a[] = {4, 5, 6, 7, 0, 1, 2};
	
	vector<int> vec(a, a+7);
	Solution S;
	
	cout<<S.findMin(vec)<<endl;
	return 0;
}
