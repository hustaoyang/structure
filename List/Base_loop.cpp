#include<iostream>
#include<stdlib.h>

using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

void CreateList(ListNode ** p, int key)
{
    ListNode* first_node = (ListNode*)malloc(sizeof(ListNode));
    first_node->m_nKey = key;
    first_node->m_pNext = NULL;

    if(*p == NULL)
	*p = first_node;
    else
    {
	first_node->m_pNext = *p;
	*p = first_node;
    }

    return ;
}

ListNode* Find_node(ListNode* pRoot, int key)
{
    if(pRoot == NULL)
	return NULL;

    while(pRoot != NULL)
    {
	if(pRoot->m_nKey == key)
	    return pRoot;
         
         pRoot = pRoot->m_pNext;
    }
     
    return NULL;
}

void Print(ListNode* pRoot)
{
     if(pRoot == NULL)
	return;
     else
     {
	cout<<pRoot->m_nKey<<endl;
	Print(pRoot->m_pNext);
     }

     return;
}

bool create_loop(ListNode* pRoot, ListNode* p)
{
     if(pRoot == NULL || p == NULL)
	return false;
  
     while(pRoot->m_pNext != NULL)
	pRoot = pRoot->m_pNext;

     pRoot->m_pNext = p;
     
     return true;
}

bool check_loop(ListNode* pRoot)
{
     if(pRoot == NULL)
	return false;

     ListNode* fast_node = pRoot;
     ListNode* low_node = pRoot;

     while(fast_node != NULL)
     {
	fast_node = fast_node->m_pNext->m_pNext;
	low_node = low_node->m_pNext;
        
	if(low_node == fast_node)
	   return true;
     }

     return false;
}



int main(void)
{
    int A[] = {1, 3, 5, 7, 9, 11};
    int B[] = {3, 2, 99, 23, 9, 232};
    ListNode * Root = NULL;
    ListNode * Rootb = NULL;

    for(int i = 0; i < 6; ++i)
    {
	//CreateList(&Root, A[i]);
	CreateList(&Rootb, B[i]);
    }

    Print(Rootb);
    
    ListNode* p = Find_node(Rootb, 23);

    if(!create_loop(Rootb, p))
	cout<<"create loop list failed"<<endl;
  
    if(!check_loop(Rootb))
	cout<<"the list have not loop"<<endl;
    
    return 0;
}
