// Source : https://leetcode.com/problems/swap-nodes-in-pairs/#/description
// Author : ljin029
// Date   : 2017-03-28

/********************************************************************************** 
* 
* Given a linked list, swap every two adjacent nodes and return its head.
* 
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* 
* Your algorithm should use only constant space. You may not modify the values in the list, 
* only nodes itself can be changed.
* 
*               
**********************************************************************************/
/**
* Definition for singly-linked list.
* struct ListNode {
*	   int val;
*	   struct ListNode *next;
* };
*/

struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode dummy;
	struct ListNode *prev = &dummy;
	struct ListNode *current = head;

    // Since the head will be changed, the dummy node will be used to point to head
	dummy.next = head;
	while (current && current->next)
	{
		prev->next = current->next;
		current->next = current->next->next;
		prev->next->next = current;
		prev = current;
		current = current->next;
	}
	return dummy.next;
}


