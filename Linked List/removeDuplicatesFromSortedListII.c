// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/#/description
// Author : ljin029
// Date   : 2017-03-29

/********************************************************************************** 
* 
* Given a sorted linked list, delete all nodes that have duplicate numbers, 
* leaving only distinct numbers from the original list.
* 
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
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
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return head;
    
    struct ListNode dummy;
    struct ListNode* current = head;
    struct ListNode* prev = &dummy;
    
    dummy.next = head;
    while ( current )
    {
        while ((current->next) && (current->val == current->next->val))
        {
            current = current->next;
        }
        if ( prev->next == current )
        {
            prev = prev->next;
        }
        else
        {
            prev->next = current->next;
        }
        current = current->next;
    }
    
    return dummy.next;
}


