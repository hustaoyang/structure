#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct BTNode 
{
     char c_value;
     struct BTNode *lchild, *rchild;

}BTNode, *BTree;

void CreateBTree(BTree &T)
{
     char c;
     cin>>c;

    if(c == '#')
    {
	T = NULL;
    }
    else
    {
	T = (BTree)malloc(sizeof(BTNode));
	T->c_value = c;
	
	CreateBTree(T->lchild);

	CreateBTree(T->rchild);
    }
}

void print(BTree T)
{
     if(T->c_value != '#')
     {
	cout<<T->c_value<<endl;
     }
}

void PreOrder(BTree T)
{
     if(T != NULL)
     {
	print(T);
	PreOrder(T->lchild);
	PreOrder(T->rchild);   
     }
}

void InOrder(BTree T)
{
     if (T != NULL)
     {
	InOrder(T->lchild);
	print(T);
	InOrder(T->rchild);
     }
}

void PostOrder(BTree T)
{
     if (T != NULL)
     {
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	print(T);
     }
}

//Get the tree's node sum

int GetNodeSum(BTree T)
{
    if(T != NULL)
	return (GetNodeSum(T->lchild) + GetNodeSum(T->rchild) + 1);
}

int GetTreeDeep(BTree T)
{
    if(T != NULL)
	return (GetTreeDeep(
}


int main(void)
{
    BTree  Ptr;
    CreateBTree(Ptr);
    
/*    PreOrder(Ptr);
    cout<<"\n"<<endl;
    InOrder(Ptr);
    cout<<"\n"<<endl;
    PostOrder(Ptr);
//    cout<<"\n"<<endl;
*/
     int i = GetNodeSum(Ptr);
     cout<<i<<endl;
    return 0;
}

