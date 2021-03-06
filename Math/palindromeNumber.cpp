// Source : https://oj.leetcode.com/problems/palindrome-number/
// Author : ljin029
// Date   : 2017-08-22

/********************************************************************************** 
* 
* Determine whether an integer is a palindrome. Do this without extra space.
* 
* 
* Some hints:
* 
* Could negative integers be palindromes? (ie, -1)
* 
* If you are thinking of converting the integer to string, note the restriction of using extra space.
* 
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
* you know that the reversed integer might overflow. How would you handle such case?
* 
* There is a more generic way of solving this problem.
* 
*               
**********************************************************************************/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x==0) return true;
        
        int sum=0;
        int tmp = x;
        while(x!=0){
            sum = sum * 10 + x%10;
            x /= 10;
        }
        if (sum == tmp) return true;
        else return false;
    }
};


