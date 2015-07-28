#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		return set<int>(nums.begin(), nums.end()).size() < nums.size();
	}
};

int main()
{
	int a[] = {4, 2, 1, 8, 9, 99, 1};
	vector<int> vec(a, a+7);

	Solution S;
	if (S.containsDuplicate(vec))
		cout<<"Yes "<<endl;

	
	return 0;
}
