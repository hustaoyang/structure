#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n < 1)
            return;

        int nums1_move = m - 1;
        int nums2_move = n - 1;

        int result = m + n - 1;
        //nums1.insert(m, result, 0);
        
        
        while(nums1_move >= 0 && nums2_move >= 0)
        {
            if (nums1[nums1_move] > nums2[nums2_move])
                nums1[result--] = nums1[nums1_move--];
            else
                nums1[result--] = nums2[nums2_move--];
        }
        
        while(nums2_move >= 0)
            nums1[result--] = nums2[nums2_move--];

        return;
    }
};

int main()
{   
    int a[] = {1, 3, 5, 7, 9, 0, 0, 0, 0, 0, 0, 0, 0};
    int b[] = {2, 4, 4, 6};

    vector<int> vec1(a, a + 13);
    vector<int> vec2(b, b + 4);

    Solution S;
    S.merge(vec1, 5, vec2, 4);

    int len = vec1.size();
    for (int i = 0; i < len; ++i)
        cout<<vec1[i]<<" ";

    return 0;
}
