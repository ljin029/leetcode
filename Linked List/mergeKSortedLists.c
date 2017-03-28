// Source : https://leetcode.com/problems/merge-k-sorted-lists/#/description
// Author : ljin029
// Date   : 2017-03-28

/********************************************************************************** 
* 
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
* 
* using Divide and Conquer          
* The idea is to pair up K lists and merge each pair in linear time using O(1) space. After first cycle, 
* K/2 lists are left each of size 2*N. After second cycle, K/4 lists are left each of size 4*N and so on. 
* We repeat the procedure until we have only one list left.
**********************************************************************************/
/**
* Definition for singly-linked list.
* struct ListNode {
*	   int val;
*	   struct ListNode *next;
* };
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode dummy;
	struct ListNode *tail = &dummy;

	while(l1 && l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	
	tail->next = (l1?l1:l2);
	return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

	int end = listsSize-1;
	while (end>0)
	{
		int begin = 0;
		while(begin<end)
		{
			lists[begin] = mergeTwoLists(lists[begin], lists[end]);
			begin++, end--;
		}
	}
	
	return lists[0];
}


