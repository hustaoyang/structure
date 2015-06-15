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

ListNode* check_loop(ListNode* pRoot)
{
     if(pRoot == NULL)
	return NULL;

     ListNode* fast_node = pRoot;
     ListNode* low_node = pRoot;

     while(fast_node != NULL)
     {
	fast_node = fast_node->m_pNext->m_pNext;
	low_node = low_node->m_pNext;
        
	if(low_node == fast_node)
	   return low_node;
     }

     return NULL;
}

ListNode* split_loop(ListNode* low_node)
{
     if(low_node == NULL)
	return NULL;
 
     ListNode* split_node = low_node->m_pNext;
     low_node->m_pNext = NULL;

     return split_node;
}

int find_loop_length(ListNode* p)
{
    if(p == NULL)
	return 0;

    int length = 1;
    ListNode* move_node = p;

    while(move_node->m_pNext != p)
    {
	length++;
	move_node = move_node->m_pNext;
    }
	
    return length;
}

int find_list_length(ListNode* pRoot)
{
    if(pRoot == NULL)
	return 0;

    int count = 0;
    while(pRoot != NULL)
    {
	count++;
	pRoot = pRoot->m_pNext;
    }
    
    return count;
}

ListNode* find_loop_first_node(ListNode* List1, int length1, ListNode* List2                              ,int length2)
{
    if(List1 == NULL || List2 == NULL || length1 == 0 || length2 == 0)
	return NULL;
    int length = length1 > length2 ? (length1-length2) : (length2-length1);
    
    if(length1 > length2)
    {
	while(length > 0)
	{
	    List1 = List1->m_pNext;
	    length--;
        }
    }
    else
    {
	while(length > 0)
	{
	    List2 = List2->m_pNext;
	    length--;
	}
    }

    while(List1 != NULL || List2 != NULL)
    {
	if(List1 == List2)
	   return List1;
        
        List1 = List1->m_pNext;
        List2 = List2->m_pNext;
    }

    return NULL;

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
    
    if(create_loop(Rootb, p))
	cout<<"create loop list succed"<<endl;
    
    ListNode* loop_node = check_loop(Rootb);
    if(loop_node != NULL)
	cout<<"the list have  loop"<<endl;

    int count = find_loop_length(loop_node);
        cout<<"the length of loop list is "<<count<<endl;
    
    ListNode* splitNode = split_loop(loop_node);

    int list_length1 = find_list_length(Rootb);
    int list_length2 = find_list_length(splitNode);
   
    ListNode* find_first_loop_node = find_loop_first_node(Rootb, 
                     list_length1, splitNode, list_length2);

    if(find_first_loop_node != NULL)
	cout<<"the first loop node is "<<find_first_loop_node->m_nKey<<endl;
    

    return 0;
}
