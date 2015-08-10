#include<iostream>
#include <exception>
#include <new>
#include <string>

using namespace std;

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
            //return NULL;
           throw new exception("Invalid input.");
    }

    int *now = InOrderStart;
    while (now <= InOrderStart && *now != *PreOrderStart)
        ++now;

    if (now == InOrderEnd && *now != *InOrderEnd)
        //return NULL;
        throw new exception("Invalid input.");

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

void print(BTree tree)
{
    if (NULL == tree)
        return ;

    print(tree->lchild);
   // cout<<tree->i_value<<" ";
    print(tree->rchild);
    cout<<tree->i_value<<" ";
}

int main(void)
{
    int InOrder[] = {5, 7, 9, 12, 15, 17, 25, 27, 29, 35};
    int PreOrder[] = {15, 9, 7, 5, 12, 25, 17, 29, 27, 35};
    
    BTree rebuild_tree = RebuildBinaryTree(InOrder, PreOrder, 10);

    if (rebuild_tree != NULL)
        print(rebuild_tree);
    return 0; 
}
