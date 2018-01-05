// Source : https://oj.leetcode.com/problems/add-two-numbers/
// Author : ljin029
// Date   : 2018-01-04

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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* prev = NULL;
        ListNode* temp;
        int sum = 0, carry = 0;
        
        while (l1 || l2)
        {
            sum = carry + (l1?l1->val:0) + (l2?l2->val:0);

            carry = (sum>=10)?1:0;
            sum %= 10;
            
            temp = new ListNode(sum);
            
            if (!res) res = temp;
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
            temp = new ListNode(carry);
            prev->next = temp;
        }
        return res;
    }
};


