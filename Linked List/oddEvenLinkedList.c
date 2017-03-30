// Source : https://leetcode.com/problems/odd-even-linked-list/
// Author : Hao Chen
// Date   : 2016-01-16

/*************************************************************************************** 
 *
 * Given a singly linked list, group all odd nodes together followed by the even nodes. 
 * Please note here we are talking about the node number and not the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space complexity 
 * and O(nodes) time complexity.
 * 
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 * 
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in 
 * the input. 
 * The first node is considered odd, the second node even and so on ...
 * 
 * Credits:Special thanks to @aadarshjajodia for adding this problem and creating all 
 * test cases.
 ***************************************************************************************/

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) 
       return head;
    struct ListNode* odd = head;
    struct ListNode* even = odd->next;
    struct ListNode* evenHead = even;
    
    while ((even && even->next) && (odd && odd->next))
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    
    return head;
}

