#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        int length = numbers.size();
        if (length < 1)
            return false;

        sort(numbers.begin(), numbers.end());
        
        int count_zero = 0;
        for (int i = 0; i < length; ++i) {
            if (0 == numbers[i])
                count_zero++;
        }

        if (length == count_zero)
            return true;

        int min = count_zero;
        int max = count_zero + 1;
        int count_sub = 0;
        for (; max < length; ++max) {
            if (numbers[max] == numbers[min])
                return false;

            if (numbers[max] > numbers[min] + 1)
                count_sub += numbers[max] - numbers[min] - 1;

            min = max;
        }
        
        if (count_sub <= count_zero)
            return true;
        else 
            return false;
    }
};

int main()
{
    int a[] = {1, 3, 2, 6, 4};
    vector<int> vec(a, a + 5);
    
    Solution S;
    if (S.IsContinuous(vec))
        cout<<"yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
