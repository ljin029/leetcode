// Source : https://leetcode.com/problems/rotate-list/#/description
// Author : ljin029
// Date   : 2017-03-29

/********************************************************************************** 
* 
* Given a list, rotate the list to the right by k places, where k is non-negative.
* 
* For example:
* Given 1->2->3->4->5->NULL and k = 2,
* return 4->5->1->2->3->NULL.
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

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || k==0) return head;
    
    struct ListNode* pHead = head;
    int len=1;
    while (pHead && pHead->next)
    {
        len++;
        pHead = pHead->next;
    }
    pHead->next = head;
    int i;
    for (i=1; i < (len-(k%len)); i++)
    {
        head = head->next;
    }
    pHead = head->next;
    head->next = NULL;
    
    return pHead;
    
} 

