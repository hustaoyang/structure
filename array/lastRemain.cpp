#include<iostream>

using namespace std;

//#define  N   100
/*
void lastRemain(int *array, int len, int m)
{
     int  n = len;
     int k = 0;
     int l = 0;
     array[1] = 0;
     while(n > 1)
     {
        while(k < m)
        {
             l = (l++)%len + 1;
             if(array[l] != 0)
             {
                 k++;
             }
        }
        
	    array[l] = 0;
	    n--;
        k = 0;
     }
    
    return;
}
*/
class Solution {
public:
    int LastRemaining_solution(unsigned int n, unsigned int m)
    {
        if (m < 1 || n < 1)
            return -1;

        int last = 0;
        for (int i = 2; i <= n; ++i)
            last = (last + m) % i;
    
        return last;
    }
};


int main(void)
{   
    unsigned int n;
    unsigned int m;
    Solution  S;

    while (cin>>n>>m)
        cout<<S.LastRemaining_solution(n, m)<<endl;    
    /*
    int A[N+1];
    int n = 10;
    for(int i = 0; i <= N; ++i)
	A[i] = i;

    lastRemain(A, n, 1);

    for(int i = 1; i <= n; ++i)
    {
    	if(A[i] != 0)
           cout<<A[i]<<endl;
    }
    */

    return 0;
}
