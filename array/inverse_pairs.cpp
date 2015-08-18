#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int InversePairs (vector<int> data) {
        int len = data.size();
        if (len < 1)
            return 0;

        vector<int> copy(data.begin(), data.end());
        
        return do_inverse_pairs(data, copy, 0, len - 1);
    }
    int do_inverse_pairs(vector<int> &data, vector<int>& copy, int start, int end)
    {
        if (start == end)
            return 0;

        int mid = (end - start) / 2;
        int start_len = start + mid;
        int copy_len = end;

        int left = do_inverse_pairs(copy, data, start, start_len);
        int right = do_inverse_pairs(copy, data, start_len + 1, end);

        int i = start_len;
        int j = end;
        int count = 0;
        while (i >= start && j >= start_len + 1)
        {
            if (data[i] > data[j])
            {       
                count += (j - start_len);
                copy[copy_len--] = data[i--];
            }
            else
                copy[copy_len--] = data[j--];
        }

        while (i >= start)
            copy[copy_len--] = data[i--];
        while (j > start_len)
            copy[copy_len--] = data[j--];

        return (count + left + right);
    }
};

int main()
{
    int a[] = {7, 5, 6, 4};
    vector<int> vec(a, a + 4);
    Solution  S;
    cout<<S.InversePairs(vec)<<endl;
    return 0;
}
