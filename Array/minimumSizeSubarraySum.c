// Source : https://leetcode.com/problems/minimum-size-subarray-sum/
// Author : ljin029
// Date   : 2017-04-18

/********************************************************************************** 
 * 
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray 
 * of which the sum = s. If there isn't one, return 0 instead.
 * 
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 * 
 * click to show more practice.
 * 
 * More practice:
 * 
 * If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

 /*
  * Req'd solution O(n log n), the binary search is O(log n) so that this solution uses binary search algorithm.
  * Using extra space to store the cumulative sum[i] of the nums[0, i-1], these sum is strictly increasing since
  * the array is non-negative. Then, a subarray sum(s) can be expressed as the difference between two
  * cumulative sum.
  *
  * Hence, given a start index of the cumulative sum array, the other end index of this sum array can be searched
  * using binary search to meet the condition of the minimum length of a contiguous subarry of which the sum>=s.
  * 
  * Time: O(N log n)
  * Space: O(1)
  */


  int binarySearch(int* sum, int key, int start, int end)
  {
	  while(start <= end){
		  int mid = (start+end)>>1;
		  if (sum[mid]>=key){
			  end=mid-1;
		  }else {
			  start=mid+1;
		  }
	  }

	  // sum[start] >= key (as req'd sum >=s)
	  return start;
  }
  int minSubArrayLen(int s, int* nums, int numsSize) {
	  if (numsSize==0 || !nums) return 0;
	  int n = numsSize+1;
	  int *sum = (int*) malloc(n*sizeof(int));
	  
	  if (!sum) return 0;
	  int i, res=INT_MAX;
	  sum[0]=0;
	  for(i=0; i<numsSize; ++i){
		  sum[i+1] = sum[i] + nums[i];
	  }
	  
	  for(i=0; i<n; ++i){
		  int end = binarySearch(sum, sum[i]+s, i+1, n-1);
		  if(end==n) break;
		  if (res>(end-i)) res=end-i;
	  }
	  
	  free(sum);
	  return res==INT_MAX?0:res;
  }

