// Source : https://oj.leetcode.com/problems/reverse-words-in-a-string/
// Author : Hao Chen, Siwei Xu
// Date   : 2014-06-16

/********************************************************************************** 
* 
* Given an input string, reverse the string word by word.
* 
* For example,
* Given s = "the sky is blue",
* return "blue is sky the".
* 
* 
* Clarification:
* 
* What constitutes a word?
* A sequence of non-space characters constitutes a word.
* Could the input string contain leading or trailing spaces?
* Yes. However, your reversed string should not contain leading or trailing spaces.
* How about multiple spaces between two words?
* Reduce them to a single space in the reversed string.
* 
*               
**********************************************************************************/

void reverse(char* begin, char* end)
{
    char temp;
    while(begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}
void reverseWords(char *s) {
    char* begin = s;
    int len = strlen(s);
    char* end = (char*)(s+len-1);
    
    // reverse the whole string first
    reverse(begin, end);
    
    char* ch = s;
    int indx = 0;
    while (*ch)
    {
        // skip space char
        if (*ch != ' '){
            // not the first char
            if (indx!=0 && indx<len) s[indx++] = ' ';

            begin = (char*)(s+indx);
            while(*ch != ' ' &&  *ch!='\0' && indx<len){
                s[indx] = *ch++;
                ++indx;
            }
            end = (char*)(s+indx-1);
            reverse(begin, end);
            
            if (*ch == '\0') break;
        }
        ++ch;
    }

    // resize the string
    if (len >= indx)
      memset(s+indx, 0, (len-indx));
}


