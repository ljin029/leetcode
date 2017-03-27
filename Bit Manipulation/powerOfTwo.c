// Source : https://leetcode.com/problems/power-of-two/
// Author : ljin029
// Date   : 2017-03-27

/********************************************************************************** 
 * 
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *               
 *               
 *               
 **********************************************************************************/
bool isPowerOfTwo(int n) {
	 if (n<=0) return false;
	 return !(n&(n-1));
}


