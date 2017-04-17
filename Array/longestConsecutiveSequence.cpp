// Source : https://oj.leetcode.com/problems/longest-consecutive-sequence/
// Author : ljin029
// Date   : 2017-04-17

/********************************************************************************** 
* 
* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
* 
* For example,
* Given [100, 4, 200, 1, 3, 2],
* The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
* 
* Your algorithm should run in O(n) complexity.
* 
*               
**********************************************************************************/

/*
 *  The easiest way is to use sort the array, however, it takes O(nlogn) complexity.
 *  Hash Table takes O(1) run-time comlexity for searching. The elements are stored in the unordered_set.
 *  For any nums[i], it is easy to figure out whether nums[i]-1(prev consecutive) and nums[i]+i (next consecutive)
 *  are stored in the set or not.
 *  To avoid searching nums[i]-1 or nums[i]+1 more than one time, remove this element from the set until the set is empty.
 *  The length is equal to the max val of next-prev-1.
 *
 */

 class Solution {
 public:
	 int longestConsecutive(vector<int>& nums) {
		 if (nums.empty()) return 0;
		 int res = 0;
		 // Store all the elements in the Hash Table
		 unordered_set<int> s(nums.begin(), nums.end());
		 
		 for(int val : nums){
			 // if val is not in the set
			 if (!s.count(val)) continue;
			 s.erase(val);
			 int prev=val-1, next=val+1;
			 while(s.count(prev)) s.erase(prev--);
			 while(s.count(next)) s.erase(next++);
			 res = max(res, next-prev-1);
		 }
		 return res;
	 }
 };

