#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if ( len < 2)
			return 0;

		vector<int> presum(len, 0);
		int leftmin = prices[0];
		int maxsub = 0;	
		for (int i = 1; i < len; ++i)
		{	
			maxsub = max(maxsub, prices[i] - leftmin);
			presum[i] = maxsub;
			leftmin = min(leftmin, prices[i]);
		}

		int maxprofit = presum[len-1];
		int rightmax = prices[len-1];
		for (int j = len-2; j >= 0; --j)
		{
			maxprofit = max(maxprofit, rightmax - prices[j] + presum[j]);
			rightmax = max(rightmax, prices[j]);
		}

		return maxprofit;
	}
};


int main()
{	
	int a[] = { 9, 5, 7, 11, 15};
	vector<int> prices(a, a+5);

	Solution S;
	cout<<S.maxProfit(prices)<<endl;
	
	return 0;
}
