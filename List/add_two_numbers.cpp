#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* result(ListNode* l1, ListNode* l2) {
  	ListNode * ptr = l2;
	ListNode * lkey1 = l1;
	ListNode * lkey2 = l2;
	int k = 0;
	int sum = 0;
	while(lkey1->next != NULL)
	{
		sum = lkey1->val + lkey2->val + k;
	        lkey2->val = sum%10;
                k = sum - lkey2->val;
		lkey1 = lkey1->next;
		lkey2 = lkey2->next;
	 }
         sum = lkey1->val + lkey2->val + k;
	 lkey2->val = sum%10;
	 k = sum - lkey2->val;
	     
         while(lkey2->next != NULL)
	 {
		sum = lkey2 + k;
		lkey2->val = sum%10;
		k = sum - lkey2->val;
		lkey2 = lkey2->next;
	  }

          if(k > 0)
	  {
	     ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	     p->val = k;
	     p->next = NULL;
	     lkey2->next = p;
	     free(p);
	  }
          return ptr;
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         if(l1 == NULL && l2 != NULL)
	    return l2;
         if(l1 != NULL && l2 == NULL)
	    return l1;

         ListNode * lkey1 = l1;
	 ListNode * lkey2 = l2;
         while((lkey1->next != NULL) && (lkey2->next != NULL))
	{
            lkey1 = lkey1->next;
	    lkey2 = lkey2->next;
	}
	
         if (lkey1->next == NULL)
	     return result(l1, l2);
	 else 
	     return result(l2, l1);
    }
};

int main(void)
{

}
