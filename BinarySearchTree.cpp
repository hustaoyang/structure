#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct BTNode
{
    int i_value;
    struct BTNode *lchild, *rchild;
}BTNode, *BTree;

void InsertNode(BTree &T, int key)
{
    if(T == NULL)
    { 
	//BTree pNode;
        T = (BTree)malloc(sizeof(BTNode));
        T->i_value = key;
        T->lchild = T->rchild = NULL;

	//T = pNode;
    }
    else
    {
	if(key == T->i_value)
	    return;
	else if(key < T->i_value)
	    InsertNode(T->lchild, key);
	else
	    InsertNode(T->rchild, key);
    }
}

void Print(BTree T)
{
     if(T != NULL)
	cout<<T->i_value<<endl;
}

void PreOrderTree(BTree T)
{
    if(T != NULL)
    {
	Print(T);
	PreOrderTree(T->lchild);
	PreOrderTree(T->rchild);
    }
}

void SearchTreetoList(BTree T)
{
    BTree pFirstLeft, pLastLeft, pFirstRight, pLastRight;
 
}


void InOrderTree(BTree T)
{
    if(T != NULL)
    {
	InOrderTree(T->lchild);
	Print(T);
	InOrderTree(T->rchild);
    }
}


int main(void)
{
     BTree Ptr = NULL;
     int  A[10] = {15, 9, 7, 5, 12, 25, 17, 29, 27, 35};
     
     int i;
     for(i = 0; i< 10; i++)
	InsertNode(Ptr, A[i]);
     
     PreOrderTree(Ptr);

     //cout<<"\n"<<endl;

     //InOrderTree(Ptr);

     return 0;
}
