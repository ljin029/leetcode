// Source : https://oj.leetcode.com/problems/linked-list-cycle/
// Author : ljin029
// Date   : 2017-04-28

/********************************************************************************** 
* 
* Given a linked list, determine if it has a cycle in it.
* 
* Follow up:
* Can you solve it without using extra space?
* 
*               
**********************************************************************************/

/*
 * if there is a cycle in the list, then we can use two pointers travers the list.
 *
 * one pointer traverse one step each time, another one traverse two steps each time.
 *
 * so, those two pointers meet together, that means there must be a cycle inside the list.
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
	 bool hasCycle(ListNode *head) {
		if(!head || !head->next) return false;
		ListNode* fast = head;
		ListNode* slow = head;
		
		while(fast->next && fast->next->next){
			fast = fast->next->next;
			slow = slow->next;
			if(fast==slow) return true;
		}
		return false;
	 }
 };


