// Source : https://leetcode.com/problems/reverse-linked-list/#/description
// Author : ljin029
// Date   : 2017-03-28

/********************************************************************************** 
 * 
 * Reverse a singly linked list.
 * 
 * click to show more hints.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 * 
 *               
 **********************************************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
	 
	 if ( head == NULL )
	   return head;
	   
	 struct ListNode* current = head;
	 struct ListNode* prev = NULL;
	 struct ListNode* next = NULL;
	 
	 while ( current != NULL )
	 {
		 next = current->next;
		 current->next = prev;
		 prev = current;
		 current = next;
	 }

	 return prev;
}

