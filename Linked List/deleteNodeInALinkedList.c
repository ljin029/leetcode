// Source : https://leetcode.com/problems/delete-node-in-a-linked-list/
// Author : ljin029
// Date   : 2017-03-30

/********************************************************************************** 
 * 
 * Write a function to delete a node (except the tail) in a singly linked list, given 
 * only access to that node.
 * 
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with 
 * value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 * 
 **********************************************************************************/

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    
    if ( node == NULL )
      return;
      
    struct ListNode* temp;
    node->val = node->next->val;
    temp = node->next;
    node->next = node->next->next;
    free(temp);
    
}

