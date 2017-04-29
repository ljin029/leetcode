// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Author : ljin029
// Date   : 2017-04-29

/*************************************************************************************** 
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 * 
 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 * 
 * Follow up:
 * What if the given array is already sorted? How would you optimize your algorithm?
 * What if nums1's size is small compared to num2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that you
 * cannot load all elements into the memory at once?
 * 
 ***************************************************************************************/


/*
 *  If the given array is not sorted, and the memory is limited
 *  Or If the given array is already sorted, and the memory is limited or m ~ n.
 *  The solution:
 *  1) Two pointers solution
 *  2) Time:  O(max(m, n) * log(max(m, n)))
 *  3) Space: O(1)
 *
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i=0, j=0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i<nums1.size() && j<nums2.size()){
            if (nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                ++i, ++j;
            }else if (nums1[i] > nums2[j]){
                ++j;
            }else ++i;
        }
        return res;
    }
};

/*
*  If the given array is already sorted, and the memory is limited, and (m << n or m >> n).
*  The solution:
*  1) Binary search solution.
*  2) Time:  O(min(m, n) * log(max(m, n)))
*  3) Space: O(1)
*
*/


/*
*  If the given array is not sorted and the memory is unlimited.
*  The solution:
*  1) Hash solution
*  2) Time:  O(m + n)
*  3) Space: O(min(m, n))
*
*/

