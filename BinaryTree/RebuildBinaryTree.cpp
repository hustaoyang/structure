#include<iostream>
#include <exception>
#include <new>
#include <string>
#include <vector>

using namespace std;

/*
typedef struct BTNode 
{
    int i_value;
    BTNode *lchild, *rchild;

}BTNode, *BTree;

BTree construct_tree(int *PreOrderStart, int *PreOrderEnd, int *InOrderStart, int *InOrderEnd);


BTree RebuildBinaryTree(int *InOrder, int *PreOrder, int len)
{
    if(InOrder == NULL || PreOrder == NULL || len <= 0)
	    return NULL;

    return construct_tree(PreOrder, PreOrder + len - 1, PreOrder, PreOrder + len - 1);
}

BTree construct_tree(int *PreOrderStart, int *PreOrderEnd,
                     int *InOrderStart, int *InOrderEnd)
{

    BTree pRoot = new BTNode();
    pRoot->i_value = PreOrderStart[0];
    pRoot->lchild = pRoot->rchild = NULL;

    if (PreOrderStart == PreOrderEnd)
    {
        if (InOrderStart == InOrderEnd && *PreOrderStart == *InOrderStart)
            return pRoot;
        else
            return NULL;
           //throw new exception("Invalid input.");
    }

    int *now = InOrderStart;
    while (now <= InOrderStart && *now != *PreOrderStart)
        ++now;

    if (now == InOrderEnd && *now != *InOrderEnd)
        return NULL;
        //throw new exception("Invalid input.");

    int left_len = now - InOrderStart;
    int *left_preOrderEnd = PreOrderStart + left_len;
    if (left_len > 0)
    {
        pRoot->lchild = construct_tree(PreOrderStart + 1, left_preOrderEnd,
                                      InOrderStart, now - 1);
    }
    if (left_len < PreOrderEnd - PreOrderStart)
    {
        pRoot->rchild = construct_tree(left_preOrderEnd + 1, PreOrderEnd,
                                       now + 1, InOrderEnd);
    }

    return pRoot;

    
}
*/

// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        int len1 = pre.size();
        int len2 = in.size();
        
        if (len1 < 0 || len1 != len2)
            return NULL;
        
        TreeNode* re_node = do_reConstruct(pre, 0, len1 - 1, in, 0, len1 - 1);
        
        return re_node;
    }   
private:
    static TreeNode* do_reConstruct(vector<int>& pre, int pre_start, int pre_end, vector<int>& in, int in_start, int in_end)
    {
        TreeNode* root = new TreeNode();
        root->val = pre[pre_start];
        root->left = root->right = NULL;
        
        if (pre_start == pre_end)
        {
        	if (in_start == in_end && in[in_start] == in[in_end])
                return root;
            else
                return NULL;
        }
        
        int move = in_start;
        while (move <= in_end && in[move] != pre[pre_start])
            ++move;
        
        if (move == in_end && in[move] != pre[pre_start])
            return NULL;
       	int len = move - in_start; 
        if (len  > 0)
        {
        	root->left = do_reConstruct(pre, pre_start + 1, pre_start + len, in, in_start, move - 1);
        }
		if (in_end - move > 0)
		{
			root->right = do_reConstruct(pre, pre_start + len + 1, pre_end, in, move + 1, in_end);
		}	
		
		return root;
	}
};

void print(TreeNode* tree)
{
    if (NULL == tree)
        return ;

    print(tree->left);
   // cout<<tree->i_value<<" ";
    print(tree->right);
    cout<<tree->val<<" ";
}



int main(void)
{
    //int InOrder[] = {5, 7, 9, 12, 15, 17, 25, 27, 29, 35};
    //int PreOrder[] = {15, 9, 7, 5, 12, 25, 17, 29, 27, 35};
    
	int PreOrder[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int InOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};

	vector<int> ino(InOrder, InOrder + 8);
	vector<int> pre(PreOrder, PreOrder + 8);

    //BTree rebuild_tree = RebuildBinaryTree(InOrder, PreOrder, 10);
	
	Solution S;
	TreeNode* rebuild_tree = S.reConstructBinaryTree(ino, pre);
    if (rebuild_tree != NULL)
        print(rebuild_tree);
    return 0; 
}
