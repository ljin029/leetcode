// Source : https://leetcode.com/problems/intersection-of-two-arrays/
// Author : ljin029
// Date   : 2017-04-29

/*************************************************************************************** 
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * 
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 ***************************************************************************************/

 /*
  *  The solution:
  *  1) Sort the two arrays
  *  2) Using two pointers: check elements in two array
  *  3) If nums1[i] > nums2[j], increment j
  *  4) If nums2[j] > nums1[i], increment i
  *  5) nums1[i] == nums2[j], push into vector if nums1[i] not in the vector
  *
  */


class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	  vector<int> res;
	  int i=0, j=0;
	  sort(nums1.begin(), nums1.end());
	  sort(nums2.begin(), nums2.end());
	  while(i<nums1.size() && j<nums2.size()){
		  if (nums1[i]<nums2[j]) ++i;
		  else if (nums1[i]>nums2[j]) ++j;
		  else{
			  if (res.empty() || res.back()!=nums1[i]){
				  res.push_back(nums1[i]);
			  }
			  ++i, ++j;
		  }
	  }
	  return res;
  }
};

