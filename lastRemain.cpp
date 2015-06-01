#include<iostream>

using namespace std;

#define  N   100

void lastRemain(int *array, int len, int m)
{
     int  n = 1;
     int k=1;
     while(1)
     {
        
        k = (k+m-1)%len;
	if(array[k] != 0)
	{
	   array[k] = 0;
	   n++;
        }
        
        if(n == (len-1))
	   return;
     }

}
int main(void)
{
    int A[N];
    for(int i = 0; i < N; ++i)
	A[i] = i;
  
    lastRemain(A, N, 5);
    
    for(int i =0; i < N; ++i)
	if(A[i] != 0)
           cout<<A[i]<<endl;
	   

    return 0;
}
