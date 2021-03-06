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

void Delete_node(ListNode* pRoot, ListNode* deletenode)
{
     if(pRoot == NULL || deletenode == NULL)
	return ;
     
     if(deletenode->m_pNext != NULL)
     {
	 deletenode->m_nKey = deletenode->m_pNext->m_nKey;
         ListNode* q = deletenode->m_pNext;
         deletenode->m_pNext = deletenode->m_pNext->m_pNext;
         free(q);
     }
     else
     {
	while(pRoot != NULL)
	{
	    if(pRoot->m_pNext == deletenode)
	    {
		pRoot->m_pNext = NULL;
		free(deletenode);
	    }
            
            pRoot = pRoot->m_pNext;
	}
     }

     return;
}

ListNode* deleteDuplication(ListNode* pHead)
{
	if (NULL == pHead)
            return pHead;
        
        ListNode* move = pHead;
        ListNode* remove = pHead->m_pNext;
        while (NULL != remove)
        {
            if (move->m_nKey == remove->m_nKey)
                remove = remove->m_pNext;
            else if (move->m_pNext != remove)
            {
                move->m_pNext = remove;
                move = remove;
                remove = remove->m_pNext;
            }
            else
            {
                move = move->m_pNext;
                remove = remove->m_pNext;
            }
        }
        
        move->m_pNext = NULL;
        
        return pHead;
}
int main(void)
{
    int A[] = {1, 3, 5, 7, 9, 11};
    int B[] = {5, 4, 4, 3, 3, 2, 1};
    ListNode * Root = NULL;
    ListNode * Rootb = NULL;

    for(int i = 0; i < 7; ++i)
    {
	//CreateList(&Root, A[i]);
	CreateList(&Rootb, B[i]);
    }

    Print(Rootb);

	Root = deleteDuplication(Rootb);

	Print(Rootb);

    //cout<<endl;
    //ListNode* Find = find_n_node(Rootb, 4);
    //cout<<Find->m_nKey<<endl;
 
    //ListNode* mid = find_mid_node(Rootb);
    //cout<<mid->m_nKey<<endl;

    //ListNode* p = Find_node(Rootb, 99);
    //Delete_node(Rootb, p);
    //Print(Rootb);

    return 0;
}
