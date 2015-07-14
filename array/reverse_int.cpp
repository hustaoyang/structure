#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
	int ret = 0; 
        
        while(x != 0)
	{
	    ret = ret*10 + x%10;
	    x /= 10;
	}
 
        return ret;
    }
};

int main(void)
{
    int x = -1234;
    Solution S;
   
    cout<<S.reverse(x)<<endl;

    return 0;
}
