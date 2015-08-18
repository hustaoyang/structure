#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int FistNotRepeatChar (string str) {
        
        int len = str.size();
        if (len < 1)
            return -1;

        unsigned int hash_table[256] = {0};
        
        int i = 0;
        while (str[i] != '\0')
            hash_table[str[i++]]++;

        i = 0;
        while (str[i] != '\0')
        {
            if (1 == hash_table[str[i]])
                return ++i;
            
            ++i;
        }

        return -1;
    }
};

int main()
{
    Solution S;
    string s;
    while (cin>>s)
        cout<<S.FistNotRepeatChar(s)<<endl;
    return 0;
}
