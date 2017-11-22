// Source : https://leetcode.com/problems/merge-k-sorted-lists/#/description
// Author : ljin029
// Date   : 2017-11-21

/********************************************************************************** 
* 
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
* 
* using Divide and Conquer          
* The idea is to pair up K lists and merge each pair in linear time using O(1) space. After first cycle, 
* K/2 lists are left each of size 2*N. After second cycle, K/4 lists are left each of size 4*N and so on. 
* We repeat the procedure until we have only one list left.
**********************************************************************************/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):

        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        def mergeTwoLists(l1, l2):
            current = dummy = ListNode(0)
            
            while l1 and l2:
                if l1.val<l2.val:
                    current.next = l1
                    l1 = l1.next
                else:
                    current.next = l2  
                    l2 = l2.next
                current = current.next
            
            current.next = l1 or l2
            return dummy.next

        if not lists:
            return None
        
        begin, end = 0, len(lists) - 1
        while end>0:
            begin = 0
            while begin<end:
                lists[begin]=mergeTwoLists(lists[begin],lists[end]);
                begin += 1
                end -= 1
        
        return lists[0]
