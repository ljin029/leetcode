// Source : https://leetcode.com/problems/power-of-four/
// Author : ljin029
// Date   : 2017-03-27

/*************************************************************************************** 
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a power 
 * of 4.
 * 
 * Example:
 * Given num = 16, return true.
 * Given num = 5, return false.
 * 
 * Follow up: Could you solve it without loops/recursion?
 * 
 * Credits:Special thanks to @yukuairoy  for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/
 /*
 1 => 1
10 => 2
100 => 4
1000 => 8
10000 => 16
100000 => 32
1000000 => 64
10000000 => 128
100000000 => 256
1000000000 => 512
10000000000 => 1024
100000000000 => 2048
1000000000000 => 4096
10000000000000 => 8192
100000000000000 => 16384
power of four is located in the odd pos
 */
bool isPowerOfFour(int num) {
    
    // power of two && 1 in odd position
    return ( !(num&(num-1)) && (num&0x55555555));
}

