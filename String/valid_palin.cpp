#include<iostream>
#include<string>
#include<ctype.h>
#include<algorithm>
#include<iterator>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		string::iterator left = s.begin(), right = s.end() - 1;
	while (left < right) {
		while(!::isalnum(*left) && left < right) 
			++left;
		while(!::isalnum(*right) && left < right)
			 --right;
		if (*left != *right) 
			return false;
		else
		{
	 		left++, right--; 
		}
	}
	return true;
     }
};

int main()
{
    Solution A;
     
    string S1("A man, a plan, a canal: Panama");
    string S2("race a cazr");

    if(A.isPalindrome(S2))
	cout<<S2<<" is a palindrome."<<endl;
    else 
	cout<<S2<<" is not a plindrome."<<endl;
    
    return 0;
}
