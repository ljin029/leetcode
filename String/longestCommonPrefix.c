// Source : https://oj.leetcode.com/problems/longest-common-prefix/
// Author : ljin029
// Date   : 2017-04-05

/********************************************************************************** 
* 
* Write a function to find the longest common prefix string amongst an array of strings.
* 
* Input  : {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
* Output : "gee"
* Reference: http://www.geeksforgeeks.org/longest-common-prefix-set-1-word-by-word-matching/
**********************************************************************************/

char* findCommonPrefix(char* str1, char* str2)
{
    int len1=strlen(str1);
    int len2=strlen(str2);
    int i,j;
    
    for(i=0,j=0; i<len1&&j<len2; i++,j++)
    {
        if(str1[i]!=str2[j]) break;
    }
    
    memset(str1+i, 0, (len1-i));
    
    return str1;
}
char* longestCommonPrefix(char** strs, int strsSize) {
    if (!strsSize) return "";
    if (strsSize==1) return strs[0];
    
    char* lcp = strs[0];
    int i;
    for(i=1; i<strsSize; i++)
    {
        lcp = findCommonPrefix(lcp, strs[i]);
    }
    
    return lcp;
}


