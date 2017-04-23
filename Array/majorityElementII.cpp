// Source : https://leetcode.com/problems/majority-element-ii/
// Author : ljin029
// Date   : 2017-04-23

/********************************************************************************** 
 * 
 * Given an integer array of size n, find all elements that appear more than ? n/3 ? times. 
 * The algorithm should run in linear time and in O(1) space.
 * 
 *   How many majority elements could it possibly have?
 *   Do you have a better hint? Suggest it!
 **********************************************************************************/

 /*
 *  The solution is req'd to run in linear time and O(1) space so that sorting and hash table cannot
 *  be used. Hence, the Majority Voting Algorithm will be used to find the majority elements in the array.
 *  Reference: https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
 *
 */


 class Solution {
 public:
	 vector<int> majorityElement(vector<int>& nums) {
		 vector<int> res;
		 int n = nums.size();
 
		 int cx=0, cy=0, x=0, y=0;
		 for(auto z : nums){
			 if (x==z) ++cx;
			 else if(y==z) ++cy;
			 else if(!cx) x=z, cx=1;
			 else if(!cy) y=z, cy=1;
			 else --cx, --cy;
		 }
 
		 cx = cy = 0;
		 for(auto z: nums){
			 if (z==x) ++cx;
			 else if (z==y) ++cy;
		 }
		 
		 if(cx>n/3) res.push_back(x);
		 if(cy>n/3) res.push_back(y);
		 
		 return res;
	 }
 };


