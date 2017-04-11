// Source : https://oj.leetcode.com/problems/reverse-words-in-a-string-iii/
// Author : ljin029
// Date   : 2017-04-11

/********************************************************************************** 
* 
* Given an input string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
* 
* For example,
* Input: "Let's take LeetCode contest"
* Output: "s'teL ekat edoCteeL tsetnoc"
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

char* reverseWords(char* s) {
  int len = strlen(s);
  char *begin, *end;
  
  int indx=0;
  while(s[indx])
  {
      // process non-space char
      if(s[indx]!=' ')
      {
          begin = s+indx;
          while(s[indx]!=' ' && s[indx]!='\0' && indx<len)
          {
              ++indx;
          }
          end = s+indx-1;
          reverse(begin, end);
          if(s[indx]=='\0') break;
      }
      ++indx;
  }
  return s;
}

