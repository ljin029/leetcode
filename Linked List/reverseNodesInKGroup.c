// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/#/description
// Author : ljin029
// Date   : 2017-03-28

/********************************************************************************** 
* 
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
* 
* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
* 
* You may not alter the values in the nodes, only nodes itself may be changed.
* 
* Only constant memory is allowed.
* 
* For example,
* Given this linked list: 1->2->3->4->5
* 
* For k = 2, you should return: 2->1->4->3->5
* 
* For k = 3, you should return: 3->2->1->4->5
* 
*               
**********************************************************************************/
/**
* Reverse a link list between begin and end exclusively
* an example:
* a linked list:
* 0->1->2->3->4->5->6
* |		            |   
* begin	           end
* after call pre = reverse(begin, end)
* 
* 0->3->2->1->4->5->6
*			|   |
*			begin end
* @param begin 
* @param end
* @return the reversed list's last node(tail), which is the precedence of parameter end
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	   int val;
 *	   struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* begin, struct ListNode* end)
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
  return tail;

}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    
    if (!head || !head->next || k==1)
      return head;
      
    struct ListNode dummy;
    struct ListNode *prev = &dummy;
    int i = 0;

    dummy.next = head;
    while (head)
    {
       i++;
       if (i%k == 0)
        {
            prev = reverse(prev, head->next);
            head = prev->next;
        }
        else
        {
            head = head->next;
        }
    }
    return dummy.next;
    
}

