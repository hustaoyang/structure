#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size();
		/*
		if (len <= 1)
			return 1;

		int maxstep = nums[0];
		int result = 0;
		for (int i = 1; i < len; ++i)
		{	
			maxstep--;
			if (maxstep < 0)
				break;
			if (maxstep < nums[i])
			{
				maxstep = nums[i];
				result++;
			}
			

			if (i+maxstep >= len-1)
				break;
		}

		return result+1;
		*/
		int last = 0;
		int cur = 0;
		int result = 0;
		for (int i = 0; i < len; ++i)
		{
			if (i > last)
			{
				last = cur;
				result++;
			}

			cur = max(cur, i+nums[i]);
		}	
		
		return result;
	}
};

int main()
{
	
	int a[] = {2, 3, 1, 1, 4, 2};
	vector<int> vec(a, a+6);

	Solution S;
	cout<<S.jump(vec)<<endl;
	
	return 0;
}
