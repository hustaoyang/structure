#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        //vector<int> result;

        int len = A.size();
        vector<int> result(len, 1);
        if (len < 1)
            return result;
        
        result[len - 1] = A[len - 1];
        for (int i = len - 2; i > 0; i--)
            result[i] = result[i + 1] * A[i];

        int sum = 1;
        for (int i = 0; i < len - 1; i++)
        {
            result[i] = sum * result[i+1];
            sum *= A[i];
        }

        result[len - 1] = sum;

        return result;
    }
};

int main()
{
    //int a[] = {2, -2, 3, 5, 8, 9, 23};
    //int a[];
    vector<int> vec;

    Solution S;
    
    vector<int> output = S.multiply(vec);

    int len = output.size();
    for (int i = 0; i < len; ++i)
        cout<<output[i]<<" ";

    cout<<endl;
}
