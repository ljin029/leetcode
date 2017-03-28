// Source : https://leetcode.com/problems/sum-of-two-integers/#/description
// Author : ljin029
// Date   : 2017-03-28

/*************************************************************************************** 
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -
 * 
 * Example: 
 * Given a = 1 and b = 2, return 3.
 * 
 * Credits:
 * Special thanks to @fujiaozhu for adding this problem and creating all test cases.
 *
 ***************************************************************************************/
int getSum(int a, int b) {
    int sum =a;
    
    while (b != 0)
    {
        sum = a ^ b;
        b = (a&b)<<1;
        a = sum;
    }
    
    return sum;
}

