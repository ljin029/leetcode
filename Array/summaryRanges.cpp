// Source : https://leetcode.com/problems/summary-ranges/
// Author : ljin029
// Date   : 2017-04-20

/********************************************************************************** 
 * 
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * 
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

 class Solution {
 public:
	 vector<string> summaryRanges(vector<int>& nums) {
		 vector<string> res;
		 if (nums.size()==0) return res;
		 
		 int n = nums.size();
		 int i = 0, j;
		 while(i<n){
			 j = 1;
			 while((i+j)<n && nums[i+j]-nums[i]==j) ++j;
			 if (j==1){
			 	 // single number
				 res.push_back(to_string(nums[i]));
			 }else{
			     // contiguous number in a sequence 
				 res.push_back(to_string(nums[i]) + "->" + to_string(nums[i+j-1]));
			 }
			 i += j;
		 }
		 
		 return res;
	 }
 };

