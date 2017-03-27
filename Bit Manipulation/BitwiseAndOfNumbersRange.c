// Source : https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author : ljin029
// Date   : 2017-03-27

/********************************************************************************** 
 * 
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive. 
 * 
 * For example, given the range [5, 7], you should return 4.
 * 
 * Credits:Special thanks to @amrsaqr for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
 int rangeBitwiseAnd(int m, int n) {
 /*
   the result of a range bitwise is the common 'left header' of m and n.
 */
    int i=0;
    while (m != n)
    {
        m >>= 1;
        n >>= 1;
        ++i;
    }
    
    return (m<<i);
    
}

