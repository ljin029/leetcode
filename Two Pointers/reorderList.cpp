// Source : https://oj.leetcode.com/problems/reorder-list/
// Author : ljin029
// Date   : 2017-04-28

/********************************************************************************** 
* 
* Given a singly linked list L: L0?L1?…?Ln-1?Ln,
* reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…
* 
* You must do this in-place without altering the nodes' values.
* 
* For example,
* Given {1,2,3,4}, reorder it to {1,4,2,3}.
* 
*               
**********************************************************************************/

/*
 *	The solution:
 *	1) Using two pointers slow and fast to find the middle node and split into two lists
 *    2) Reverse the second list
 *    3) Merge the two lists
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
	 void reorderList(ListNode* head) {
		 if (!head || !head->next) return;
		 ListNode* fast = head;
		 ListNode* slow = head;
		 
		 // Find the middle node
		 while(fast&&fast->next){
			 fast = fast->next->next;
			 slow = slow->next;
		 }
		 ListNode* mid = slow->next;
		 // Seperate into two list
		 slow->next = NULL;
		 ListNode* l1 = head;
		 ListNode* l2 = reverse(mid);
		 merge(l1, l2);
	 }
	 ListNode* reverse(ListNode* head){
		 ListNode* prev = NULL;
		 ListNode* current = head;
		 ListNode* next = NULL;
		 
		 while(current){
			 next = current->next;
			 current->next = prev;
			 prev = current;
			 current = next;
		 }
		 return prev;
	 }
	 void merge(ListNode* l1, ListNode* l2){
		 while(l1 && l2){
			 ListNode* tmp1 = l1->next, *tmp2 = l2->next;
			 l1->next = l2;
			 l2->next = tmp1;
			 l1 = tmp1;
			 l2 = tmp2;
		 }
	 }
 };


