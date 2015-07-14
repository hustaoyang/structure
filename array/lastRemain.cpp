#include<iostream>

using namespace std;

#define  N   100

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


int main(void)
{
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

    return 0;
}
