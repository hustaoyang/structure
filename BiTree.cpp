#include<iostream>
#include<stdlib.h>
#include<queue>

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
    int LDeep, RDeep;
    if(T != NULL)
	return (LDeep=GetTreeDeep(T->lchild)) > (RDeep=GetTreeDeep(T->rchild)) ? (LDeep+1) : (RDeep+1);
}

void FreeTree(BTree T)
{
    ;
}

void LevelTraverse(BTree  pRoot)  
{  
    if(pRoot == NULL)  
        return;  
    queue<BTree> q;  
    q.push(pRoot);  
    while(!q.empty())  
    {  
        BTree  pNode = q.front();  
        q.pop();  
        print(pNode); // 访问节点  
        if(pNode->lchild != NULL)  
            q.push(pNode->lchild);  
        if(pNode->rchild != NULL)  
            q.push(pNode->rchild);  
    }  
    return;  
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
     //int i = GetNodeSum(Ptr);
     //int i = GetTreeDeep(Ptr);
    
    // cout<<i<<endl;
    LevelTraverse(Ptr);
    return 0;
}

