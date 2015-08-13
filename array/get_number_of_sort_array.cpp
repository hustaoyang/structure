#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int len = data.size();
		if (len < 1 || k > data[len-1] || k < data[0])
			return 0;

		int left = 0;
		int right = len - 1;
		int mid;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (k == data[mid])
				break;
			else if (k < data[mid])
				right = mid - 1;
			else 
				left = mid + 1;
		}

		int count = 0;
		if (k == data[left])
			mid = left;
		if (data[mid] == k)
		{
			int m = mid;
			while (m >= 0 && k == data[m--])
				count++;

			m = mid + 1;
			while (m < len && k == data[m++])
				count++;
		}

		return count;
	}
};


int main()
{
	int a[] = {0, 1, 2, 2, 2, 9, 93};
	vector<int> vec(a, a+7);

	Solution S;
	int k = 93;
	while (cin>>k)
		cout<<S.GetNumberOfK(vec, k)<<endl;
	return 0;
}
