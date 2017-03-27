// Source : https://leetcode.com/problems/maximum-product-of-word-lengths/
// Author : ljin029
// Date   : 2017-03-20

/*************************************************************************************** 
 *
 * Given a string array words, find the maximum value of length(word[i]) * 
 * length(word[j]) where the two words do not share common letters.
 *     You may assume that each word will contain only lower case letters.
 *     If no such two words exist, return 0.
 * 
 *     Example 1:
 * 
 *     Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 *     Return 16
 *     The two words can be "abcw", "xtfn".
 * 
 *     Example 2:
 * 
 *     Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 *     Return 4
 *     The two words can be "ab", "cd".
 * 
 *     Example 3:
 * 
 *     Given ["a", "aa", "aaa", "aaaa"]
 *     Return 0
 *     No such pair of words.    
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/
int maxProduct(char** words, int wordsSize) {
	 int i,j,len;
	 int *word;
	 
	 if (words==NULL || wordsSize ==0)
	   return 0;
	   
	 word = (int*) malloc(wordsSize * sizeof(int));
	 
	 if (!word) return 0;
	 
	 for (i=0; i<wordsSize; i++)
	 {
		 len = strlen(words[i]);
		 word[i] = 0;
		 for(j=0; j<len; j++)
		 {
		 	 // convert letter into the bit representation of 1
			 word[i] |= 1<<(words[i][j]-'a');
		 }
	 }
	 
	 int ret = 0;
	 for (i=0; i<wordsSize; i++)
	 {
		 for (j=i+1; j<wordsSize; j++)
		 {
		 	 // if two words dont share common letters, then calculate the length
			 if (!(word[i] & word[j]) && ((strlen(words[i]) * strlen(words[j])) > ret))
			 {
				 ret = strlen(words[i]) * strlen(words[j]);
			 }
		 }
	 }
	 
	 free(word);
	 return ret;
}

