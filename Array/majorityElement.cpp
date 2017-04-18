// Source : https://oj.leetcode.com/problems/majority-element/
// Author : ljin029
// Date   : 2017-04-18

/********************************************************************************** 
 * 
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.
 * 
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

 /*
 *  The solution 1 is to use Bit Manipulation. The key point lies in how to count the number of 1's for specific bit.
 *  Specifically using the mask with a bit 1 on the i-th bit, scan the whole array and count the number of elements
 *  which has i-th bit set to 1. After going through 32-bit, the result is the majority element.
 *
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, n = nums.size();
        
        for(int i=0, mask=1; i<32; ++i, mask<<=1){
            int bitCount = 0;
            for(int j=0; j<n; ++j){
                if (nums[j] & mask) ++bitCount;
                if (bitCount> (n/2)){
                    res |= mask;
                    break;
                }
            }
        }
        return res;
    }
};

