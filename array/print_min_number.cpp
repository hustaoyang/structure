#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    static bool compare(const string s1, const string s2)
    {
        string ss1 = s1 + s2;
        string ss2 = s2 + s1;

        return ss1 < ss2;
    }

    string Print_min(vector<int> numbers) {
        string result;
        
        int len = numbers.size();
        if (len < 1)
            return result;
        
        vector<string> tmp;
        for (int i = 0; i < len; ++i)
        {
            stringstream ch;
            ch<<numbers[i];
            tmp.push_back(ch.str());
        }

        sort(tmp.begin(), tmp.end(), compare);

        for (int i = 0; i < len; ++i)
            result += tmp[i];

        return result;
        
    }
};

int main()
{
    Solution S;
    int a[] = {3, 32, 321};
    vector<int> vec(a, a + 3);
    
    string ss = S.Print_min(vec);
    cout<<ss<<endl;
    return 0;
}
