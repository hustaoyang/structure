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


ListNode* ReverseIterAtively(ListNode* pHead)
{
    if(pHead == NULL)
	return NULL;
    ListNode* ReverseNode = NULL;
    ListNode* moveNode = pHead;
    ListNode* presentNode = NULL;


    while(moveNode != NULL)
    {
	presentNode = moveNode;
	moveNode = moveNode->m_pNext;
	presentNode->m_pNext = ReverseNode;
        ReverseNode = presentNode;
    }

    return ReverseNode;

}


/*
ListNode* ReverseIteratively(ListNode* pHead)
{
    ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;
    while(pNode != NULL)
    {
	// get the next node, and save it at pNext
	ListNode* pNext = pNode->m_pNext;
	// if the next node is null, the currect is the end of original
	// list, and it's the head of the reversed list
	if(pNext == NULL)
	    pReversedHead = pNode;
	// reverse the linkage between nodes
	pNode->m_pNext = pPrev;
	// move forward on the the list
	pPrev = pNode;
	pNode = pNext;
    }
    return pReversedHead;
}
*/

int main(void)
{
    int A[] = {1, 3, 5, 7, 9, 11};
    ListNode * Root = NULL;

    for(int i = 0; i < 6; ++i)
	CreateList(&Root, A[i]);

    Print(Root);

    cout<<endl;
    ListNode* Root1 = ReverseIterAtively(Root);

    Print(Root1);

    return 0;
}
