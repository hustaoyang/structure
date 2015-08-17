#include <iostream>

using namespace std;

class Solution {
public:
    int GetUglyNumber(int index) {
        if (index < 1)
            return 0;
        
        //int len = index;
        switch (index)
        {
            case 1 : return 1;
            
            case 2 : return 2;
            
            case 3 : return 3;
            
            case 4 : return 4;
        
            case 5 : return 5;
            
            default:
                    return do_ugly_number(index);
        }
    }
private:
    int static do_ugly_number(int len)
    {
        int k = len;
        
    }
};
int main()
{

    return 0;
}
