#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0; 
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) sum += diff;
        }
        
        return sum;
    }
};

int main()
{
    int a[] = {5, 3, 2, 7, 9, 8, 6, 3, 3, 7, 2, 2};
    vector<int> vec(a, a+12);

    Solution S;
    cout<<S.maxProfit(vec)<<endl;
    return 0;
}
