#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        const int row = matrix.size();
        const int col = matrix[0].size();

        if (col < 1 || row < 1)
            return false;

        int i = 0;
        int j = col - 1;
        while (i < row || j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
            {
                if (i == (row-1))
                    return false;
                else
                    ++i;
            }
            else 
            {
                if (j == 0)
                    return false;
                else 
                    --j;
            }
        }
        return false;

    }

};

int main()
{
    int a[] = {1, 1};
    vector<vector<int> > vec;
    vector<int> path(a, a+2);
    vec.push_back(path);

    Solution  S;
    int k = 0;
    while (cin>>k)
    if (S.searchMatrix(vec, k))
        cout<<"Yes"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
