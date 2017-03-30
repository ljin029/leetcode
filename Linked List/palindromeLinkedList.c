// Source : https://leetcode.com/problems/palindrome-linked-list/
// Author : ljin029
// Date   : 2017-03-30

/********************************************************************************** 
 * 
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 *               
 **********************************************************************************/

 /**
  * Definition for singly-linked list.
  * struct ListNode {
  * 	int val;
  * 	struct ListNode *next;
  * };
  */
 struct ListNode* findMidNode(struct ListNode* head)
 {
	 struct ListNode *p1=head, *p2=head;
	 
	 while(p2 && p2->next)
	 {
		 p1 = p1->next;
		 p2 = p2->next->next;
	 }
	 return p1;
 }
 
 struct ListNode* reverse(struct ListNode* head)
 {
	 struct ListNode* current = head;
	 struct ListNode* prev = NULL;
	 struct ListNode* next = NULL;
	 
	 while (current)
	 {
		 next = current->next;
		 current->next = prev;
		 prev = current;
		 current = next;
	 }
	 
	 return prev;
 }
 bool isPalindrome(struct ListNode* head) {
	 struct ListNode* pMid = findMidNode(head);
	 struct ListNode* pRev = reverse(pMid);
	 
	 struct ListNode* p = head;
	 while(p!=pMid)
	 {
		 if (p->val != pRev->val)
		   return false;
		 
		 p = p->next;
		 pRev = pRev->next;
	 }
	 
	 return true;
	 
 }


