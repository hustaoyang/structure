#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	const vector<string> keyword{" ", "", "abc", "def", "ghi", "jkl", "mno",
                                    "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        if (len < 1)
            exit(0);
        
        vector<string>  result;
		result.push_back("");
        string s;
        do_letter(result, digits, 0, s, len);

        return result;
        }    
    
    void do_letter(vector<string>& res, string& digits, int start, string out, int len)
    {
        if (start ==  len)
        {
            res.push_back(out);
            return;
        }
        else
            for (auto c : keyword[digits[start] - '0'])
            {   
                //string str = keyword[digits[start] - '0'][i];
                do_letter(res, digits, start+1, out+c, len);
            }
    }
};

int main()
{
	Solution S;
	string s("");

	vector<string> res = S.letterCombinations(s);

	int m = res.size();
	for (int i = 0; i < m; ++i)
		cout<<res[i]<<endl;

	return 0;
}
