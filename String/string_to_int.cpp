#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int len = str.size();
        if (len < 1)
            return 0;

        int flag = 1;
        
        int i = 0;
        long long num = 0;
        if (str[0] == '+')
            ++i;
        else if (str[0] == '-')
        {
            flag = -1;
            ++i;
        }

        for (; i < len; ++i)
        {
            if (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + str[i]  - '0';
            }
            else {
                num = 0;
                break;
            }
     
           if ((flag == 1 && num > INT32_MAX) || (flag == -1 && -num < INT32_MIN)) {
                    num = 0;
                    break;
           }
        }
        
        if (str[i] == '\0')
        {
            num = flag * num;
        }
        else 
        {
            num = 0;
        }

        return (int)num;
    }
};

int main() 
{
    Solution S;
    string s;
    
    while (cin>>s)
        cout<<S.StrToInt(s)<<endl;
 
    return 0;
}
