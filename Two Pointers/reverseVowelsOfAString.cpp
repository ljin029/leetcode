// Source : https://leetcode.com/problems/reverse-vowels-of-a-string/
// Author : ljin029
// Date   : 2017-04-29

/*************************************************************************************** 
 *
 * Write a function that takes a string as input and reverse only the vowels of a 
 * string.
 * 
 * Example 1:
 * Given s = "hello", return "holle".
 * 
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 * 
 ***************************************************************************************/

 /*
  *  The solution:
  *  1) Vowels: a, e, i, o, u, A, E, I, O, U
  *  2) Using two pointers: left and right
  *  3) If s[left] and s[right] are vowels, then swap
  *  4) If s[left] is vowel, move right to left
  *  5) If s[right] is vowel, move left to right
  *
  */



class Solution {
public:
  string reverseVowels(string s) {
	  int left = 0;
	  int right = s.size() - 1;
	  
	  while(left<right){
		  if (isVowels(s[left]) && isVowels(s[right])){
			  swap(s[left++], s[right--]);
		  }else if(isVowels(s[left])) --right;
		  else ++left;
	  }
	  return s;
  }
  
  bool isVowels(char c){
	  return c== 'a' || c== 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
};

