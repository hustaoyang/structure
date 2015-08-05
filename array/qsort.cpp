#include <iostream>
#include <vector>

using namespace std;

void qsort(int nums[], int len)
{
	if (len <= 1)
		return;

	int value = nums[0];
	int start = 0;
	int end = len - 1;
	while (start < end)
	{
		while (start < end && nums[end] > value)
			end--;
		nums[start] = nums[end];

		while (start < end && nums[start] <= value)
			start++;
		nums[end] = nums[start];
	}
	nums[start] = value;

	qsort(nums, start);
	qsort(nums+start+1, len - start - 1);
}

int main()
{
	int len = 7;
	int a[] = {5, 6, 1, 5, 8, 9, 4};
	//vector<int> vec(a, a+7);
	qsort(a, len);	
	for (int i = 0; i < len; i++)
		cout<<a[i]<<" ";
	
	cout<<endl;
	return 0;
}
