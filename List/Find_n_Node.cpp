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


ListNode* find_n_node(ListNode* pHead, int n)
{
     if(pHead == NULL)
	return NULL;
     ListNode* find_node = pHead;
     ListNode* move_node = pHead;

     for(int i=0; i < n; ++i)
     {
         if(move_node == NULL)
	    return NULL;
         else
	    move_node = move_node->m_pNext;
     }
     
     while(move_node != NULL)
     {
	find_node = find_node->m_pNext;
	move_node = move_node->m_pNext;
     }
     
     return find_node;
}

ListNode* find_mid_node(ListNode* pHead)
{
    if(pHead == NULL)
	return NULL;
    
    ListNode* fast_node = pHead;
    ListNode* low_node = pHead;

    int count = 0;
    while(fast_node->m_pNext != NULL)
    {
        count++;
        fast_node = fast_node->m_pNext;

        if((count%2) == 0)
 	    low_node = low_node->m_pNext;
    }     
   
    return low_node;
}

//find the last k node
ListNode* find_kth_to_tail(ListNode* pListHead, unsigned int k)
{
    if (NULL == pListHead)
        return NULL;
    ListNode* low = pListHead;
    ListNode* fast = pListHead;
    
    int move = k;
    while (NULL != fast && move > 0)
    {
        fast = fast->m_pNext;
        move--;
    }
    
    if (move >= 1)
        return NULL;

    while (NULL != fast)
    {
        fast = fast->m_pNext;
        low = low->m_pNext;
    }

    return low;
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

    cout<<endl;
    //ListNode* Find = find_n_node(Rootb, 4);
    //cout<<Find->m_nKey<<endl;
 
    //ListNode* mid = find_mid_node(Rootb);
    //cout<<mid->m_nKey<<endl;

    //Print(Root1);
    int k = 0;
    while (cin>>k)
    {
        ListNode* result = find_kth_to_tail(Rootb, k);
        cout<<result->m_nKey<<endl;
    }

    return 0;
}
