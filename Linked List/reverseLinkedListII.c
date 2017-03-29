// Source : https://leetcode.com/problems/reverse-linked-list-ii/#/description
// Author : ljin029
// Date   : 2017-03-29

/********************************************************************************** 
* 
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
* 
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
* 
* return 1->4->3->2->5->NULL.
* 
* Note:
* Given m, n satisfy the following condition:
* 1 = m = n = length of list.
* 
*               
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reverse(struct ListNode* begin, struct ListNode* end)
{
  struct ListNode* prev = begin;
  struct ListNode* current = begin->next;
  struct ListNode* next, *tail;
  
  tail = current;
  while ( current != end )
  {
	next = current->next;
	current->next = prev;
	prev = current;
	current = next;
  }
  
  begin->next = prev; // head
  tail->next = current; // tail

}
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (!head || m==n) return head;
    struct ListNode dummy;
    struct ListNode* end;
    struct ListNode* prev = &dummy;
    
    dummy.next = head;
    n-=m;
    while ((--m) && prev && (prev->next))
    {
        prev = prev->next;
    }
    end = prev->next;
    while ((n--) && end && end->next)
    {
        end = end->next;
    }
    reverse(prev, end->next);
    
    return dummy.next;
}


