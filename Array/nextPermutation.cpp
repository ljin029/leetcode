// Source : https://oj.leetcode.com/problems/next-permutation/
// Author : ljin029
// Date   : 2017-04-13

/********************************************************************************** 
* 
* Implement next permutation, which rearranges numbers into the lexicographically next 
* greater permutation of numbers.
* 
* If such arrangement is not possible, it must rearrange it as the lowest possible order 
* (ie, sorted in ascending order).
* 
* The replacement must be in-place, do not allocate extra memory.
* 
* Here are some examples. Inputs are in the left-hand column and its corresponding outputs 
* are in the right-hand column.
*
*   1,2,3 ? 1,3,2
*   3,2,1 ? 1,2,3
*   1,1,5 ? 1,5,1
*               
**********************************************************************************/

/*
 *  From the Wikipedia page, in the 14th century, a man named Narayana Pandita gives the following 
 *  classic and yet quite simple algorithm (with minor modifications in notations to fit the problem statement):
 *
 *  1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, the permutation is 
 *      sorted in descending order, just reverse it to ascending order and we are done. For example, the next 
 *      permutation of [3, 2, 1] is [1, 2, 3].
 *   2. Find the largest index l greater than k such that nums[k] < nums[l].
 *   3. Swap the value of nums[k] with that of nums[l].
 *   4. Reverse the sequence from nums[k + 1] up to and including the final element nums[nums.size() - 1].
 *
 *
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()<2) return;
        
        int n = nums.size(), k = n - 2;
		// Rule 1
        while(k>=0 && nums[k]>=nums[k+1]) --k;
		// Rule 1
        if(k<0) {
            sort(nums.begin(), nums.end());
            return;
        }
            
        
        int l = n - 1;
		// Rule 2
        while(l>k && nums[k]>=nums[l]) --l;
		// Rule 3		
        swap(nums[k], nums[l]);
		// Rule 4
        sort(nums.begin()+k+1, nums.end());
    }
};

