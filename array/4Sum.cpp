#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > result;
        if (nums.size() < 4)
            return result;

        int target = 0;
        
        sort(nums.begin(), nums.end());

        vector<int>::iterator last = nums.end();
        for (vector<int>::iterator l = nums.begin(); l < last-3; ++l)
        {
	    
   	    if (l > nums.begin() && *l == *(l-1)) continue;
	    for (vector<int>::iterator i = l + 1; i < last-2; ++i)
	    {
		    if ( i > l+1 && *i == *(i-1)) continue;
		    vector<int>::iterator j = i + 1;
		    
		    vector<int>::iterator k = last-1;
		    while (j < k) {
		        if (*i + *j + *k + *l < target) {
		            ++j;
		            while (*j == *(j - 1) && j < k) ++j;
			} else if (*i + *j + *k + *l > target) {
			    --k;
			    while(*k == *(k + 1) && j < k) --k;
			} else {
			    result.push_back({*l, *i, *j, *k });
			    ++j;
			    --k;
			while(*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
		        }
		    }
	    }
        }
	return result;
}
};

int main()
{
    int a[] = {1, 0, -1, 0, -2, 2};
    vector<int> S(a, a+6);
    Solution re;
    vector<vector<int> > sum =  re.threeSum(S);
    
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
