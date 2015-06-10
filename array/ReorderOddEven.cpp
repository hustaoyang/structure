#include<iostream>

using namespace std;

void Reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int a);

void ReorderOddEven(int *pData, unsigned int length)
{
    if(pData == NULL || length == 0)
	return ;
    Reorder(pData, length, isEven);
}

void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
    int *pLow = pData;
    int *pHigh = pData + length - 1;

    while(pLow < pHigh)
    {
	while(func(*pLow) && pLow < pHigh)
	    pLow ++;
	
	while(!func(*pHigh) && pLow < pHigh)
	    pHigh --;

        int tmp = *pLow;
	*pLow = *pHigh;
	*pHigh = tmp;

    }
    
    return;
}

bool isEven(int a)
{
      if(a & 1)
	return true;
}
int main(void)
{
    int A[] = {2, 7, 8, 9, 1, 3, 4, 26, 11};
    
    for(int i = 0; i < 9; ++i)
	cout<<A[i]<<" ";
    
    cout<<endl;

    ReorderOddEven(A, 9);

    for(int i = 0; i < 9; ++i)
	cout<<A[i]<<" ";
    cout<<endl;

    return 0;
}
