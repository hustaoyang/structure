#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

class BinaryTree {
public:
	TreeNode* reateBTree(vector<int>& vec)
	{
		int len = vec.size();
		if (len < 1)
			return NULL;
		TreeNode* tRoot = new TreeNode(vec[i]);
	}
};

int main()
{
	
	return 0;
}
