#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums, int target) {
        vector<vector<int> > result;
        if (nums.size() < 3)
            return result;

       // int target = 0;
        
        sort(nums.begin(), nums.end());

        vector<int>::iterator last = nums.end();
        for (vector<int>::iterator i = nums.begin(); i < last-2; ++i)
        {
            vector<int>::iterator j = i + 1;
            if (i > nums.begin() && *i == *(i-1)) continue;
            vector<int>::iterator k = last-1;
            while (j < k) {
                if (*i + *j + *k < target) {
                    ++j;
                    while (*j == *(j - 1) && j < k) ++j;
		} else if (*i + *j + *k > target) {
		    --k;
		    while(*k == *(k + 1) && j < k) --k;
		} else {
		    result.push_back({ *i, *j, *k });
		    ++j;
		    --k;
		while(*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
                }
            }
        }
	return result;
}
};

int main()
{
    int a[] = {-1, 2, 1, -4};
    vector<int> S(a, a+4);
    Solution re;
    vector<vector<int> > sum =  re.threeSum(S, 1);
    
    int m = sum.size();
    int n = sum[0].size();
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout<<sum[i][j]<<" ";
        cout<<endl;
    }
 
	return 0;
}
