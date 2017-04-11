// Source : https://leetcode.com/problems/first-unique-character-in-a-string/
// Author : ljin029
// Date   : 2017-04-11

/*************************************************************************************** 
 *
 * Given a string, find the first non-repeating character in it and return it's index. 
 * If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * Note: You may assume the string contain only lowercase letters.
 ***************************************************************************************/

#define NO_OF_CHARS 256
 
int firstUniqChar(char* s) {
	 if (!s) return -1;

	 int array[NO_OF_CHARS] = {0};
	 int i;
	 char* str = s;
	 for(i=0; str[i]; i++)
	 {
		 array[str[i]]++;
	 }
	 for (i=0; s[i]; i++)
	 {
		 if (array[s[i]] == 1)
		   return i;
	 }
	 return -1;
}


