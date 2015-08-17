#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;    
        int row_len = matrix.size();
        int col_len = matrix[0].size();

        if (row_len < 1 || col_len < 1)
            return result;

        int start = 0;
        while (row_len > 2 * start && col_len > 2 * start)
            print(matrix, result, start++, row_len, col_len);

        return result;
            
    }
private:
    void static print(vector<vector<int> >& matrix,vector<int> & res, int start, int row, int col)
    {
        int in_start = start;
        int in_end = row - start - 1;
        int in_col_end = col - start - 1;

        for (int k = start; k <= in_col_end; ++k)
            res.push_back(matrix[start][k]);
        if (in_start < in_end)
        {
            for (int k = start + 1; k <= in_end; ++k)
                res.push_back(matrix[k][in_col_end]);
        }
        if (in_start < in_end && in_start < in_col_end)
        {
            for (int k = in_col_end - 1; k >= start; --k)
                res.push_back(matrix[in_end][k]);
        }
        if (in_start < in_end - 1 )
        {
            for (int k = in_end - 1; k >= start + 1; --k)
                res.push_back(matrix[k][start]);
        }
    }
};

int main()
{
    vector<vector<int> > vec;
    //vector<int> path;

    for (int i = 1; i < 5; ++i)
    {
        vector<int> path;
        //for (int j = 1; j < 2; ++j)
            path.push_back(i);
        
        vec.push_back(path);
    }

    Solution S;
    
    vector<int> res = S.printMatrix(vec);

    int k = res.size();
    for (int i = 0; i < k; ++i)
        cout<<res[i]<<" ";
    return 0;
}
