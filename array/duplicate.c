#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

bool duplicate(int numbers[], int length, int *duplication) {
    if (length < 1)
        return false;
    
    bool flag = true;
    

    int i = 0;

    *duplication = -1;

    for (; i < length; ++i)
    {
        int index = numbers[i];
        if (index >= length)
        {
            numbers[i] -= length;
        }
        if (numbers[index] >= length)
        {
            *duplication = index;
            break;
        }
        else
            numbers[index] += length; 
    }

    if (*duplication == -1)
        flag = false;

    return flag;
}

int main()
{
    int a[] = {3, 3, 0, 1, 4, 1, 4, 5};
    int len = 8;
    
    int c  = 1;
    int *dup = &(c);

    if (duplicate(a, len, dup))
        printf("%d ", *dup);

    return 0;
}
