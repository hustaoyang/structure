#include<iostream>
#include<stdio.h>
#include<queue>
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

//The sum of Node in the k level
int  GetNodeNumKLevel(BTree T, int k)
{   
    if(T == NULL)
	return 0;
    if(k < 1)
	return 0;
    if(k == 1)
	return 1;
    
    int leftSum = GetNodeNumKLevel(T->lchild, k-1);
    int rightSum = GetNodeNumKLevel(T->rchild, k-1);
    return (leftSum + rightSum);
}

int GetNodeNumLeaf(BTree T)
{
    if(T == NULL)
	return 0;
    if(T->lchild == NULL && T->rchild == NULL)
	return 1;

    int leftSum = GetNodeNumLeaf(T->lchild);
    int rightSum = GetNodeNumLeaf(T->rchild);
    return (leftSum + rightSum);
}

int GetTreeLevel(BTree T)
{
    if(T == NULL)
	return 0;
    int leftLevel = GetTreeLevel(T->lchild);
    int rightLevel = GetTreeLevel(T->rchild);
    return leftLevel > rightLevel ? (leftLevel+1):(rightLevel+1);
}

bool StructureCmp(BTree T1, BTree T2)
{
    if(T1 == NULL && T2 == NULL)
	return true;
    if(T1 != NULL || T2 != NULL)
	return false;

    bool leftbool = StructureCmp(T1->lchild, T2->lchild);
    bool rightbool = StructureCmp(T1->rchild, T2->rchild);
    
    return (leftbool && rightbool);
}

//递归进行
bool AVLTree(BTree T)
{
    if(T == NULL)
	return true;
    bool leftAVL = AVLTree(T->lchild);
    bool rightAVL= AVLTree(T->rchild);
    
    int leftLevel = GetTreeLevel(T->lchild);
    int rightLevel = GetTreeLevel(T->rchild);
    int k = (leftLevel - rightLevel) >= 0 ? (leftLevel - rightLevel) : (rightLevel - leftLevel);

    if ( k <= 1 && k >= 0)
	return true;
    else 
	return false;
}

bool FindNode(BTree root, int key)
{
     if(root == NULL)
	return false;
 
     if(root->i_value == key)
	return true;

     bool found = FindNode(root->lchild, key);
     if(!found)
	found = FindNode(root->rchild, key);
     return found;
}

BTree GetLastCommonParent(BTree root, int key1, int key2)
{
     if(root == NULL || !(FindNode(root,key1)) || !(FindNode(root, key2)))
	return NULL;
     if(root->i_value == key1 || root->i_value == key2)
	return root;
     if(FindNode(root->lchild, key1))
     {
	if(FindNode(root->rchild, key2))
	   return root;
	else 
	   return GetLastCommonParent(root->lchild, key1, key2);
     }
     else
     {
  	if(FindNode(root->lchild, key2))
	   return root;
	else
	   return GetLastCommonParent(root->rchild, key1, key2);
     }     
}

int GetLen(BTree T)
{
    int lenth = 0;
    while(T != NULL)
	lenth += 1;
}
int GetLeftLen(BTree T)
{
     if(T == NULL)
	return 0;
     else 
	return (GetLen(T->lchild) + 1);
}

int GetRightLen(BTree T)
{
    if(T == NULL)
	return 0;
    else
   	return (GetLen(T->rchild) + 1);

}

int GetMaxDistance(BTree T)
{
    int MaxDistance;
    
}
/*
int GetMaxDistance(BTree T, int &leftMax, int &rightMax)
{
    
    if(T == NULL)
    {
        leftMax = 0;
	rightMax = 0;
	return 0;
    }
    else
    {
        int leftLen, rightLen;
	int leftMaxIn, rightMaxIn;
        if(T->lchild != NULL)
	{
	    leftLen = GetMaxDistance(T->lchild, leftMax, rightMax) + 1;
	    leftMaxIn = (leftLen > leftMaxIn ? leftLen : leftMaxIn);
	    
	}
        else
	{
	    leftLen = 0;
	    leftMaxIn = 0;
	    
	}

        if(T->rchild != NULL)
	{
	    rightLen = GetMaxDistance(T->rchild, leftMax, rightMax) + 1;
	    rightMaxIn = (rightLen > rightMaxIn ? rightLen : rightMaxIn);
	}
   	else
	{
	    rightLen = 0;
	    rightMaxIn = 0;
        }	
    }
}
*/

bool IsCompleteBinaryTree(BTree  pRoot)  
{  
    if(pRoot == NULL)  
        return true;  
    queue<BTree> q;  
    q.push(pRoot);  
    while(!q.empty())  
    {  
        BTree  pNode = q.front();  
        q.pop();  

        if(pNode->lchild != NULL && pNode->rchild == NULL)
	{    
	    q.push(pNode->lchild);
	    while(!q.empty())
	    {	
		pNode = q.front();
		q.pop();
		if(pNode->lchild != NULL || pNode->rchild != NULL)
		    return false;	
	    }
	    
	    return true;
	}
	else if(pNode->lchild == NULL && pNode->rchild == NULL)
	{
	    while(!q.empty())
	    {
		pNode = q.front();
		q.pop();
               	if(pNode->lchild != NULL || pNode->rchild != NULL)
            	    return false;	
	    }    
	    
            return true;
	}
	else if(pNode->lchild == NULL && pNode->rchild != NULL)
	    return false;
	else
	{
	    q.push(pNode->lchild);
	    q.push(pNode->rchild);
	}
    }  
}  

int main(void)
{
     BTree Ptr1 = NULL;
     int  A[10] = {15, 9, 7, 5, 12, 25, 17, 29, 27, 35};
     int  B[10] = {15, 9, 7, 5, 12, 25, 17, 29, 20, 35};
     int  C[5] = {15, 10, 17, 5 ,14}; 
     BTree Ptr2 = NULL;
     BTree Ptr = NULL;

     int i;
     for(i = 0; i< 10; i++)
     {
      	InsertNode(Ptr1, A[i]);
	//InsertNode(Ptr2, B[i]);
        InsertNode(Ptr, i+1);
     }
     
     for(i = 0; i < 5; i++)
	InsertNode(Ptr2, C[i]);
     //PreOrderTree(Ptr);

     //cout<<"\n"<<endl;

     //InOrderTree(Ptr);
     //int sum = GetNodeNumKLevel(Ptr, 3);
     //int sum = GetNodeNumLeaf(Ptr);
     //cout<<sum<<endl;
     /*
     if(StructureCmp(Ptr1, Ptr2))
	cout<<"The structure of Ptr1 and Ptr2 are the same"<<endl;
     else
	cout<<"The structure of Ptr1 and Ptr2 aren't the same"<<endl;
     
      //
      if(AVLTree(Ptr1))
	cout<<"yes"<<endl;
      else
	cout<<"no"<<endl;  
     */

      //BTree pNode = GetLastCommonParent(Ptr1, 5, 35);
      //cout<<pNode->i_value<<endl;
      //BTree pNode1 = GetLastCommonParent(Ptr1, 15, 17);
      //cout<<pNode1->i_value<<endl;
      //BTree pNode2 = GetLastCommonParent(Ptr1, 27, 35);
      //cout<<pNode2->i_value<<endl;
      if(IsCompleteBinaryTree(Ptr2))
	cout<<"Yes. The tree is complete binary!"<<endl;
      else
	cout<<"No. The tree is not complete binary!"<<endl; 
     return 0;
}
