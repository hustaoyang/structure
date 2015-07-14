#include<iostream>

using namespace std;

class Solution {
public:
	int reverse(int x) {
	        //int y;
		if(x == 0)
		   cout<<x<<endl;
		if(x < 0)
		{
			cout<<"-";
			x = -x;
		}
		while(x)
		{
		    cout<<x%10;
		    x = x/10;
		}
	    return 0;
	}
};

int main()
{
	Solution A;
	A.reverse(4322);
        cout<<endl;
        A.reverse(-5433);
	cout<<endl;
	return 0;
}
