// Source : https://leetcode.com/problems/remove-linked-list-elements/
// Author : ljin029
// Date   : 2017-03-30

/********************************************************************************** 
 * 
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

 /**
  * Definition for singly-linked list.
  * struct ListNode {
  * 	int val;
  * 	struct ListNode *next;
  * };
  */
 struct ListNode* removeElements(struct ListNode* head, int val) {
	 
	 if ( head == NULL )
	   return NULL;
	   
	 struct ListNode dummy;
	 dummy.next = head;
	 struct ListNode* current = &dummy;
	 
	 while (current->next != NULL)
	 {
	   if (current->next->val == val)
	   {
		   struct ListNode* temp;
		   temp = current->next;
		   current->next = current->next->next;
		   free(temp);
	   }
	   else
	   {
		   current = current->next;
	   }
	 }
	 
	 return dummy.next;
 }


