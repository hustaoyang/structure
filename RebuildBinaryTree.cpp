#include<iostream>

using namespace std;

typedef struct BTNode 
{
    int i_value;
    BTNode *lchild, *rchild;

}BTNode, *BTree;

BTree RebuildBinaryTree(int *InOrder, int *PreOrder, int len)
{
    if(InOrder == NULL || PreOrder == NULL || len <= 0)
	return NULL;
    BTree pRoot = (BTree)malloc(sizeof(BTNode));
    pRoot->i_value = InOrder[0];
    pRoot->lchild = pRoot->rchild = NULL;

    
}


int main(void)
{
    int InOrder[] = {5, 7, 9, 12, 15, 17, 25, 27, 29, 35};
    int PreOrder[] = {15, 9, 7, 5, 12, 25, 17, 29, 27, 35};

    return 0; 
}
