// Source : https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : ljin029
// Date   : 2017-04-27

/********************************************************************************** 
* 
* Given a linked list, remove the nth node from the end of list and return its head.
* 
* For example,
* 
*    Given linked list: 1->2->3->4->5, and n = 2.
* 
*    After removing the second node from the end, the linked list becomes 1->2->3->5.
* 
* Note:
* Given n will always be valid.
* Try to do this in one pass.
* 
*               
**********************************************************************************/

/*
 *	The solution:
 *	1) Using two pointer to traverse the linked list
 *    2) The fast pointer is moving n position ahead of the slow pointer
 *    3) Check if the fast pointer becomes NULL, then n is equal to the length of the linked list
 *    4) The slow pionter is pointed to the previous node of the deleted node
 *    5) The next of slow pointer points to the next of the next of the slow pointer
 *
 */


 /**
  * Definition for singly-linked list.
  * struct ListNode {
  * 	int val;
  * 	ListNode *next;
  * 	ListNode(int x) : val(x), next(NULL) {}
  * };
  */
 class Solution {
 public:
	 ListNode* removeNthFromEnd(ListNode* head, int n) {
		 if (n<1) return head;
		 
		 ListNode dummy(0);
		 ListNode* fast = head;
		 ListNode* slow = head;
		 dummy.next = head;
		 
		 int i = 0;
		 while(i<n && fast){
			 fast = fast->next;
			 ++i;
		 }
		 // n is equal to the length of linked list and then remove the head
		 if (!fast) return dummy.next = head->next;
		 else{
			 while(fast->next){
			 slow = slow->next;
			 fast = fast->next;
			 }
			 slow->next = slow->next->next;
		 }
 
 
		 return dummy.next;
	 }
 };

