#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int GetUglyNumber(int index) {
        if (index < 1)
            return 0;
        vector<int> vec(index, 0);
        vec[0] = 1;

        int min_index2 = 0;
        int min_index3 = 0;
        int min_index5 = 0;
        int move = 1;
        while (move < index)
        {
            int cur_min = min(2 * vec[min_index2], 3 * vec[min_index3], 5 * vec[min_index5]);
            vec[move] = cur_min;
            while (2 * vec[min_index2] <= cur_min)
                ++min_index2;
            while (3 * vec[min_index3] <= cur_min)
                ++min_index3;
            while (5 * vec[min_index5] <= cur_min)
                ++min_index5;

            ++move;
        }

        return vec[index - 1]; 
    }
private:
    static int min(int a, int b, int c)
    {
        
        int min = a < b ? a : b;
        min = min < c ? min : c;

        return min;
    }
};
int main()
{
    int index = 0;
    Solution S;
    while(cin>>index)
        cout<<"the "<<index<<" ugly number is "<<S.GetUglyNumber(index)<<endl;
    return 0;
}
