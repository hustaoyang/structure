#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
	{
		int len = input.size();
		//vector<int> result;

		if (k > len)
			return input;

		vector<int> result(k, INT_MAX);

		for (int i = 0; i < len; ++i)
		{
			if (input[i] < result[0])
				heap_sort(result, input[i]);
		}

		sort(result.begin(), result.end());

		return result;
	}
private:
	void static heap_sort(vector<int>& vec, int m)
	{
		int size_ = vec.size();
		vec[0] = m;

		int i = 0;
		while (i < size_)
		{
			if ((2*i+1) < size_)
			{	
				int tmp = 2*i + 1;
				if((2*i+2) < size_)
					tmp = vec[2*i+1] > vec[2*i+2] ? (2*i+1) : (2*i+2);

				if(vec[i] < vec[tmp])
				{
					int temp = vec[i];
					vec[i] = vec[tmp];
					vec[tmp] = temp;

					i = tmp;
				}
				else return;
				
			}
			else
				return;
		}

		return;
	}
};

int main()
{
	int a[] = {4, 5, 1, 6, 2, 7, 3, 8};

	vector<int> res(a, a+8);
	
	Solution S;
	int k =  7;
	vector<int> vec = S.GetLeastNumbers_Solution(res, k);

	for (int j = 0; j < k; ++j)
		cout<<vec[j]<<" ";

	return 0;
}
