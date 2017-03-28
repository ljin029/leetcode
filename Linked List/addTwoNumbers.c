// Source : https://leetcode.com/problems/add-two-numbers/#/description
// Author :  ljin029
// Date   : 2017-03-28

/********************************************************************************** 
* 
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
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
struct ListNode* newNode(int val)
{
	 struct ListNode *node = (struct ListNode* ) malloc(1 * sizeof(struct ListNode));
	 
	 node->val = val;
	 node->next = NULL;
	 
	 return node;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	 struct ListNode* res = NULL;
	 struct ListNode *temp, *prev = NULL;
	 int carry = 0, sum = 0;
	 
	 while ( l1 || l2 )
	 {
		 sum = carry + (l1?l1->val:0) + (l2?l2->val:0);
		 
		 carry = (sum >= 10)? 1:0;
		 
		 sum %= 10;
		 
		 temp = newNode(sum);
		 
		 if (!res)
		 {
			 res = temp;
		 }
		 else
		 {
			 prev->next = temp;
		 }
		 
		 prev = temp;
		 
		 if (l1) l1 = l1->next;
		 if (l2) l2 = l2->next;
		 
	 }
	 
	 if (carry)
	 {
		 temp->next = newNode(carry);
	 }
	 return res;
}

