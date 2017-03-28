// Source : https://leetcode.com/problems/hamming-distance/#/description
// Author : ljin029
// Date   : 2017-03-28
/*************************************************************************************** 
 *The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 *Given two integers x and y, calculate the Hamming distance.
 *Note:
 *0 = x, y < 2^31.
 *Example:
 *
 *Input: x = 1, y = 4
 *Output: 2
 *Explanation:
 *1   (0 0 0 1)
 *4	 (0 1 0 0)
	     |    |
*The above arrows point to positions where the corresponding bits are different.
 ***************************************************************************************/
 const uint8_t lookup[]     = {  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,   
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

int hammingDistance(int x, int y) {
    return (hammingWeight(x^y));
}

