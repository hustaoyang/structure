#include<iostream>

using namespace std;

bool FindGreatSumOfSubArray(int *array,
			    int len,
                            int &GreatSum)
{
    if(array == NULL || len == 0)
	return false;

    int CurSum = GreatSum = 0;
    for(int i = 0; i < len; ++i)
    {
	CurSum += array[i];
    
  	if(CurSum < 0)
	   CurSum = 0;
        
  	if(CurSum > GreatSum)
	   GreatSum = CurSum;
    }

    if(GreatSum == 0)
    {
  	GreatSum = array[0];
        for(int i = 1; i < len; ++i)
	   if(array[i] > GreatSum)
 		GreatSum = array[i];
    }
    
    return true;
    
}


int main(void)
{
    //int A[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int A[] = {-3, -5, -1, -9, -35, -89};
    int greatsum;
 
    if(FindGreatSumOfSubArray(A, 6, greatsum))
	cout<<greatsum<<endl;

    
    return 0;
}

