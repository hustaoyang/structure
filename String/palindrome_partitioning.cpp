#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string> > partition(string s) {
		const int n  = s.size();

		bool f[n][n];
		fill_n(&f[0][0], n*n, false);
		//vector<vector<string> > palindrome;
		
		f[0][0] = true;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= i; ++j)
				f[i][j] = (s[i] == s[j] && ((i -j <2) || f[i-1][j+1]));
	}
};

int main()
{
	return 0;
}
