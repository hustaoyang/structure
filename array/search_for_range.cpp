#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> result;

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
		
		if (nums[mid] != target)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}

		int m = mid;
		int n = mid;
		while (m >= 0 && nums[m] == target) --m;
		result.push_back(++m);
		
		while (n < nums.size() && nums[n] == target) ++n;
		result.push_back(--n);

		return result;
	}
};

int main()
{
	//int a[] = {5, 7, 7, 8, 8, 10};
	int a[] = {1};
	vector<int> vec(a, a+1);
	
	
	Solution S;
	int target = 0;
	vector<int> res = S.searchRange(vec, target);

	cout<<res[0]<<" "<<res[1]<<endl;
	
	return 0;
}
