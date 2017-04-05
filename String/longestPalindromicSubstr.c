// Source : https://oj.leetcode.com/problems/longest-palindromic-substring/
// Author : ljin029
// Date   : 2015-04-5

/********************************************************************************** 
* 
* Given a string S, find the longest palindromic substring in S. 
* You may assume that the maximum length of S is 1000, 
* and there exists one unique longest palindromic substring.
*               
**********************************************************************************/

#define MAX_SIZE_STR  1000
int min(int a, int b)
{
    if (a>b) return b;
    else return a;
}
char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len<2 || len>MAX_SIZE_STR ) return s;
    
    // Add $ at the begining of string
    char str[2*MAX_SIZE_STR+3] = {'$', '#', 0};
    int p[2*MAX_SIZE_STR+3]={0};
   
    int i;
    /* Insert '#' */
    int length = 2;
    for (i=0; i<len; i++)
    {
        str[2*i+2] = s[i];
        str[2*i+3] = '#';
        length += 2;
    }

    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for(i=1; i<length; i++)
    {
        p[i] = mx>i?min(p[2*id-i], mx-i):1;
        while((i-p[i] >=0) && (str[i+p[i]]==str[i-p[i]]))
        {
            ++p[i];
        }
        if (mx < i+p[i])
        {
            mx = i+p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    memset(str, 0, length);
    strncpy(str, &s[(resCenter - resLen) / 2], resLen-1);
    memset(s, 0, len);
    strncpy(s, str, resLen-1);
    //printf("s: %s\n", s);
    return s;
}

