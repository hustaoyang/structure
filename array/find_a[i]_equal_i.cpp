#include <iostream>

using namespace std;

void find(int nums[], int length)
{
	if (length < 1)
		return ;

	int left = 0;
	int right = length - 1;
	int mid = (left + right) / 2;
	while (left < right && (nums[mid] != mid+1))
	{
		if (nums[mid] > mid+1)
			right = mid-1;
		if (nums[mid] < mid+1) 
			left = mid+1;
		mid = (left + right) / 2;
	}
	
	if (nums[mid] == mid+1)
	{
		for (right = mid; right < length; ++right)
		{
			if (nums[right] == right+1)
				cout<<right+1<<" ";
		}
		
		for (left = mid - 1; left >= 0; --left)
		{
			if (nums[left] == left+1)
				cout<<left+1<<" ";
		}
		
		cout<<endl;
	}
	else
		cout<<"don't find"<<endl;
		
	return;
}

int main()
{
	//int cc[] = {0, 1};
	int cc[] = {1, 2, 3, 8, 9, 10};
	int len = 6;
	find(cc, len);
	return 0;
}
