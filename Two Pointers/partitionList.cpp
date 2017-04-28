// Source : https://oj.leetcode.com/problems/partition-list/
// Author : ljin029
// Date   : 2017-04-28

/********************************************************************************** 
* 
* Given a linked list and a value x, partition it such that all nodes less than x come 
* before nodes greater than or equal to x.
* 
* You should preserve the original relative order of the nodes in each of the two partitions.
* 
* For example,
* Given 1->4->3->2->5->2 and x = 3,
* return 1->2->2->4->3->5.
* 
*               
**********************************************************************************/

/*
 *	The solution:
 *	1) It is req'd to partition the list, the solution is using two pointers to partition into two halves
 *    2) The head of the list will be changed so that we use dummy node at the front
 *    3) The dummy_small pointer points to the smaller values less than x
 *    4) The dummy_large poiter points to the larger values >= x
 *    5) Traverse the linked list by moving head = head->next
 *    6) Concatenat of the two halves and make the last node points to NULL
 *    7) Return the dummy_small.next
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
	 ListNode* partition(ListNode* head, int x) {
		 ListNode dummy_large(0);
		 ListNode dummy_small(0);
		 ListNode* smaller = &dummy_small;
		 ListNode* larger = &dummy_large;
		 
		 while(head){
			 if(head->val < x){
				 smaller->next = head;
				 smaller = smaller->next;
			 }else{
				 larger->next = head;
				 larger = larger->next;
			 }
			 head = head->next;
		 }
		 smaller->next = dummy_large.next;;
		 larger->next = NULL;
		 
		 return dummy_small.next;
	 }
 };


