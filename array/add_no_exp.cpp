#include <iostream>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum;
        int temp;

        do {
            
            sum = num1 ^ num2;
            temp = (num1 & num2) << 1;

            num1 = sum;
            num2 =temp;
        } while (num2 != 0);

        return sum;
    }
};

int main()
{
    Solution S;
    int m;
    int n;
    
    while (cin>>m>>n)
        cout<<S.Add(m, n)<<endl;

    return 0;
}

