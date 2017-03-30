// Source : https://oj.leetcode.com/problems/intersection-of-two-linked-lists/
// Author : ljin029
// Date   : 2017-03-30

/********************************************************************************** 
 * 
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * 
 * For example, the following two linked lists: 
 * 
 *
 *    A:          a1 -> a2
 *                             \
 *                               c1-> c2 -> c3
 *                             /            
 *    B:     b1 -> b2 -> b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns. 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *               
 **********************************************************************************/
 /*
 Two pointer solution (O(n+m) running time, O(1) memory):
Maintain two pointers pA and pB initialized at the head of A and B, respectively. Then let them both traverse through the lists, one node at a time.
When pA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); similarly when pB reaches the end of a list, redirect it the head of A.
If at any point pA meets pB, then pA/pB is the intersection node.
To see why the above trick would work, consider the following two lists: A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. Since B.length (=4) < A.length (=6), pB would reach the end of the merged list first, because pB traverses exactly 2 nodes less than pA does. By redirecting pB to head A, and pA to head B, we now ask pB to travel exactly 2 more nodes than pA would. So in the second iteration, they are guaranteed to reach the intersection node at the same time.
If two lists have intersection, then their last nodes must be the same one. So when pA/pB reaches the end of a list, record the last element of A/B respectively. If the two last elements are not the same one, then the two lists have no intersections.
 */

/**
* Definition for singly-linked list.
* struct ListNode {
* 	int val;
* 	struct ListNode *next;
* };
*/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	 if (!headA || !headB) return NULL;

	 struct ListNode* p1 = headA;
	 struct ListNode* p2 = headB;
	 
	 while (p1 != p2)
	 {
		 p1 = p1?p1->next:headB;
		 p2 = p2?p2->next:headA;
	 }

	 return p1;
}

