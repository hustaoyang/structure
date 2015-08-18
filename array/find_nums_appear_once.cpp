#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
        int len = data.size();
        if (len < 2)
            return;
        unsigned int num = 0;
        for (int i = 0; i < len; ++i)
            num ^= data[i];

        int last_bit = bit_last(num);

        *num1 = 0;
        *num2 = 0;
        for (int i = 0; i < len; ++i)
        {
            if (is_bit_last(data[i], last_bit))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }

        return;
    }

    int bit_last(unsigned int n)
    {
        int count = 0;
        while ((n & 1) == 0) {
                n = n>>1;
                count++;
          }
          return count;
    }

    bool is_bit_last(int k, int count)
    {
        k = k>>count;
        return (k & 1);
    }
};

int main()
{
    int a[] = {2, 3, 2, 4, 5, 6, 4, 5};
    vector<int> vec(a, a + 8);
    Solution S;
    int c = 0;
    int b = 0;

    S.FindNumsAppearOnce(vec, &c, &b);

    cout<<c<<" "<<b<<endl;
    
    return 0;
}
