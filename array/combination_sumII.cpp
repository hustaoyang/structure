#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
	
	sort(candidates.begin(), candidates.end());

	vector<vector<int> > result;
	vector<int> path;

	int len = candidates.size();
	if (len < 1)
		return result;

	
	do_combinationSum(candidates, result, 0, target, path);

	return result;
	
	}
private:
	static void do_combinationSum(vector<int>& input, vector<vector<int> >& output, int start, int  sub, vector<int>& tmp)
	{
		if (sub == 0)
		{
			output.push_back(tmp);
			return;
		}

		for (int i = start; i < input.size(); ++i)
		{
			if (input[i] > sub)
				return ;
			if (i != start && input[i] == input[i-1]) continue;
			//if (sub - input[i] < 0)
			//	return;
			tmp.push_back(input[i]);
			do_combinationSum(input, output, i + 1, sub - input[i], tmp);
			tmp.pop_back();
		}
		
	}
	 
};

int main()
{
	int a[] = {10, 1, 2, 6, 7, 1, 5};
	vector<int> vec(a, a+7);
	int target = 8;

	Solution S;
	vector<vector<int> > result = S.combinationSum2(vec,target);
	
	int m = result.size();
	for (int i = 0; i < m; ++i)
	{
		int n = result[i].size();
		for (int k = 0; k < n; ++k)
			cout<<result[i][k]<<" ";
		cout<<endl;
	}
	
	return 0;
}
