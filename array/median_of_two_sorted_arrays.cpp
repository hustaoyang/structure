#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        int left1 = 0;
        int left2 = 0;

        int right1 = nums1.size();
        int right2 = nums2.size();

        double result = 0;

        while(left1 < right1 || left2 < right2)
        {
            int mid1 = (left1 + right1) / 2;
            int mid2 = (left2 + right2) / 2;

            if(nums1[mid1] == nums2[mid2])
            {
                result = nums1[mid1] + ;
                return result;
            }
            else if(nums1[mid1] < nums2[mid2])
            {
                left1 = mid1 + 1;
                right2 = mid2 - 1;
            }
            else
            {
                right1 = mid1 -1;
                left2 = mid2 + 1;
            }
        }

        result = (nums1[left1] + nums2[left2]) / 2;
       
        return result;

        
    }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};

    vector<int> nums1(a, a+4);
    vector<int> nums2 (a+4, a+8);

    Solution S1;
    cout<<S1.findMedianSortedArrays(nums1, nums2)<<endl;

    return 0;
}
