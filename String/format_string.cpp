#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    void Format_string(char str[], int len)
    {
        
        if (NULL == str || len < 1)
            return;

        int i = 0;
        int j = 0;

        if (' ' == str[0])
        {
            while(' ' == str[j])
                ++j;
            if (j == len)
            {
                str[0] = '\0';
                return;
            }
            else
            {
                while( j < len)
                {
                    if (' ' != str[j])
                        str[i++] = str[j++];
                    else
                    {
                        if (j < len-1 && ' ' != str[j+1])
                        {
                            str[i++] = ' ';
                            j++;
                        }
                        else
                            j++;
                    }
                }
            }

            str[i] = '\0';
        }
        else
        {
            while( j < len)
                {
                    if (' ' != str[j])
                        str[i++] = str[j++];
                    else
                    {
                        if (j < len-1 && ' ' != str[j+1])
                        {
                            str[i++] = ' ';
                            j++;
                        }
                        else
                            j++;
                    }
                }
           str[i] = '\0';
        }

        return;
    }
};

int main()
{
    Solution S;
    char str[] = "  i am    a letter  child!  ";
    int len = strlen(str);
    //cout<<len<<endl;
    S.Format_string(str, len);

    int len1 = strlen(str);
    cout<<len1<<endl;
    for (int i = 0; i < len1; ++i)
        cout<<str[i];
    cout<<endl;
    return 0;
}
