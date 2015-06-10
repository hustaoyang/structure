#include<iostream>

using namespace std;

int NumberOf1_Solution1(int i)
{
    int n = 0;
    
    while(i)
    {
	if(i & 1)
	    n++;

        i = i >> 1;
    }
    
    return n;
}


int main(void)
{
    int N = 10;
    
    int count = NumberOf1_Solution1(N);
    cout<<N<<" have "<<count<<" number 1 in it Binary Number"<<endl;
    return 0;
}
