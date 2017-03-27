// Source : https://leetcode.com/problems/number-of-1-bits/
// Author : ljin029
// Date   : 2017-03-27

/********************************************************************************** 
* 
* Write a function that takes an unsigned integer and returns the number of ’1' bits it has 
* (also known as the Hamming weight).
* 
* For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, 
* so the function should return 3.
* 
* Credits:Special thanks to @ts for adding this problem and creating all test cases.
*               
**********************************************************************************/
const uint8_t lookup[]	   = {	0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,   
								1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,	
								1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,	 
								2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,	 
								1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,	  
								2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,	 
								2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,	 
								3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,	 
								1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,	 
								2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,	 
								2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,	 
								3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,	 
								2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,	 
								3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,	 
								3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,	 
								4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};

int hammingWeight(uint32_t n) {
	register uint8_t *p = (uint8_t *)&n;

	return (lookup[p[0]] + lookup[p[1]] + lookup[p[2]] + lookup[p[3]]);
}


