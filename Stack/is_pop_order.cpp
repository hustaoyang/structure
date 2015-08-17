#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        int len1 = pushV.size();
        int len2 = popV.size();
        if (len1 != len2)
            return false;
        if (len1 < 1 && len2 < 1)
            return true;

        int i = 0;
        //int j = 0;
        int k = 0;
       /* 
        stack<int> temp;
        while(pushV[i] != popV[k] && i < len1)
        {
            temp.push(pushV[i]);
            ++i;
        }

        if (i == len1)
            return false;

        i++;
        k++;
        while (!temp.empty() || i < len1 || k < len1 )
        {

            if (temp.top() == popV[k])
            {
                temp.pop();
                k++;
            }
            else if (i < len1 && k < len1 && pushV[i] == popV[k])
            {
                i++;
                k++;
            }
            else
            {
                if (i < len1)
                    temp.push(pushV[i++]);
                else return false;
            }
        }

        return true; 
    */
    }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {4, 3, 5, 2, 1};

    vector<int> vec1(a, a + 5);
    vector<int> vec2(b, b + 5);

    Solution S;
    if (S.IsPopOrder(vec1, vec2))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    return 0;
}
