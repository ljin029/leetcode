// Source : https://oj.leetcode.com/problems/zigzag-conversion/
// Author : ljin029
// Date   : 2017-04 -05

/********************************************************************************** 
* 
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
* (you may want to display this pattern in a fixed font for better legibility)
* 
* P   A   H   N
* A P L S I I G
* Y   I   R
* 
* And then read line by line: "PAHNAPLSIIGYIR"
* 
* Write the code that will take a string and make this conversion given a number of rows:
* 
* string convert(string text, int nRows);
* 
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
* 
*               
**********************************************************************************/

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if ((numRows <=1))
      return s;
    
    char str[2048] = {0};
    int step = 2*numRows-2;
    int i, j, pos=0, ind=0;
    for(i=0; i<numRows; i++)
    {
        for(j=i; j<len; j+=step)
        {
          str[ind++] = s[j];
          if (i!=0 && i!=(numRows-1)) // every row except for 1st and last row
          {
              pos = j + step - 2 * i;
              if (pos<len)
                str[ind++] = s[pos];
          }
        }
    }
    memset(s, 0, len);
    strncpy(s, str, len);

    return s;
}


