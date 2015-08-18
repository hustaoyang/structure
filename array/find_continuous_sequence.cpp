#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > find_continuous(int sum) {
	
	vector<vector<int> > result;
    if (sum <= 0)
        return result;

	//vector<int> path;
	//for(int i = 1; i <= (sum + 1) / 2; ++i)
	    do_find(result, sum);

	return result;
	
	}
private:
    void do_find(vector<vector<int> >& output, int sum)
    {
        int i = 1; 
        int j = 2;
        int count = 3;
        if (sum < count)
            return;

        while (i < ((sum+1) / 2))
        {
            if (sum == count)
            {
                vector<int> path;
                for (int k = i; k <= j; ++k)
                    path.push_back(k);
                output.push_back(path);
                count -= i;
                i++;
            }
            else if (sum > count) {
                    ++j;
                    count += j;
            }
            else
            {
                count -= i;
                ++i;
            }
        }

        return ;
    }
    /*
	void do_find(vector<vector<int> >& output,int k, int sub)
	{
        int sum = 0;
        vector<int> tmp;
		for (int j = k; j <= (sub + 1) / 2; ++j)
        {
            tmp.push_back(j);
            sum += j;
            if (sum == sub)
            {   
                if (tmp.size() >= 2)
                    output.push_back(tmp);
                return;
            }
            if (sum > sub)
                return;
        }

        return;
		
	}
    */
};

int main()
{
	//int a[] = {2, 3, 6, 7};
	//vector<int> vec(a, a+4);
	int target = 7;

	Solution S;
    while(cin>>target)
    {
	    vector<vector<int> > result = S.find_continuous(target);
	
	    int m = result.size();
	    for (int i = 0; i < m; ++i)
	    {
		    int n = result[i].size();
		    for (int k = 0; k < n; ++k)
			    cout<<result[i][k]<<" ";
		    cout<<endl;
	    }
    }
	
	return 0;
}
