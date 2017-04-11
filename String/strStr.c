// Source : https://oj.leetcode.com/problems/implement-strstr/
// Author : ljin029
// Date   : 2017-04-05

/********************************************************************************** 
* 
* Implement strStr().
* 
* Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
* 
*               
**********************************************************************************/

int strStr(char* haystack, char* needle) {

    int m=strlen(haystack);
    int n=strlen(needle);
    if (!n) return 0;
    
    if (m<n) return -1;

    int i,j;
    for (i=0; i<=(m-n); i++)
    {
        for(j=0; j<n; j++)
        {
            if (haystack[i+j] != needle[j])
              break;
        }
        if (j==n) return i;
    }
    return -1;
}


