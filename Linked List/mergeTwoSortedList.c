// Source : https://leetcode.com/problems/merge-two-sorted-lists/#/description
// Author : ljin029
// Date   : 2017-03-28

/********************************************************************************** 
* 
* Merge two sorted linked lists and return it as a new list. The new list should be 
* made by splicing together the nodes of the first two lists.
*               
**********************************************************************************/
/**
* Definition for singly-linked list.
* struct ListNode {
*	   int val;
*	   struct ListNode *next;
* };
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode dummy;
	struct ListNode *tail = &dummy;
	
	while(l1 && l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	
	tail->next = (l1?l1:l2);
	return dummy.next;
}

