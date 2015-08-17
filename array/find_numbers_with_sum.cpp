#include <iostream>
#include <vector>
#include <cstdint>
#include <limits>

using namespace std;
class Solution {
public:
    vector<int> FindNumber(vector<int> array, int sum)
    {
        vector<int> result(2, 0);
        
        int len = array.size();
        if (len <= 1)
            return result;

        int mul = INT32_MAX;
        int left = 0;
        int right = len - 1;
        while (left < right)
        {
            int cur_sum = array[left] + array[right];
            if (cur_sum == sum)
            {
                int cur_mul = array[left] * array[right];
                if (cur_mul < mul)
                {
                    result[0] = array[left++];
                    result[1] = array[right--];
                    mul = cur_mul;
                }
                else
                {
                    left++;
                    right--;
                }
            }
            else if (cur_sum > sum)
                --right;
            else 
                ++left;
        }
        
        return result;
    }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    vector<int> vec(a, a + 20);

    Solution S;
    int sum = 17;
    while(cin>>sum) {
        vector<int> output = S.FindNumber(vec, sum);
        cout<<output[0]<<" "<<output[1]<<endl;
    }

    return 0;
}
