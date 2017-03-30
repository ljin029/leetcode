// Source : https://leetcode.com/problems/add-two-numbers-ii/#/solutions
// Author : ljin029
// Date   : 2017-03-30

/*************************************************************************************** 
 *
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The most significant digit comes first and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list. 
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 * 
 * Example:
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
 ***************************************************************************************/

 /**
  * Definition for singly-linked list.
  * struct ListNode {
  * 	int val;
  * 	struct ListNode *next;
  * };
  */
 struct ListNode* newNode(int val)
 {
	  struct ListNode *node = (struct ListNode* ) malloc(1 * sizeof(struct ListNode));
	  
	  node->val = val;
	  node->next = NULL;
	  
	  return node;
 }
 
 int getLength(struct ListNode* head)
 {
	 int ret = 0;
	 
	 while (head)
	 {
		 head = head->next;
		 ++ret;
	 }
	 
	 return ret;
 }
 
 /* The length of l1 is greater than the one of l2 */
 struct ListNode* add(struct ListNode* l1, struct ListNode* l2, int diff)
 {
	 if (!l1) return NULL;
	 struct ListNode* res = (diff == 0)? newNode(l1->val + l2->val):newNode(l1->val);
	 struct ListNode* post = (diff == 0)? add(l1->next, l2->next, 0):add(l1->next, l2, (diff-1));
	 
	 if (post && (post->val > 9))
	 {
		 post->val %= 10;
		 ++res->val;
	 }
	 res->next = post;
	 
	 return res;
 }
 struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	 int n1 = getLength(l1);
	 int n2 = getLength(l2);
	 
	 if (n1==0) return l2;
	 else if (n2==0) return l1;
	 
	 struct ListNode* head = newNode(1);
	 head->next = (n1 > n2)? add(l1, l2, (n1-n2)): add(l2, l1, (n2-n1));
	 
	 if (head->next->val > 9)
	 {
		 head->next->val %= 10;
		 return head;
	 }
	 
	 return head->next;
	 
 }


