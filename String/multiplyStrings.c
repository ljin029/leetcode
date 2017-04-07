// Source : https://oj.leetcode.com/problems/multiply-strings/
// Author : ljin029
// Date   : 2017-04-07

/********************************************************************************** 
* 
* Given two numbers represented as strings, return multiplication of the numbers as a string.
* 
* Note: The numbers can be arbitrarily large and are non-negative.
*               
**********************************************************************************/

char* multiply(char* num1, char* num2) {
    if (!num1 || !num2) return " ";
    
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    
    int* int_res = (int*) malloc((len1+len2)*sizeof(int));
    
    if (!int_res) return NULL;
    
    int i,j;
    int k = len1 + len2 - 2;
    memset(int_res, 0, (len1+len2));
    for(i=0; i<(len1+len2);i++)
    {
        int_res[i]=0;
    }
    for(i=0; i<len1; i++)
    {
        for(j=0; j<len2; j++)
        {
            int_res[k-(i+j)] += (num1[i] - '0')*(num2[j] - '0');
        }
    }
    
    int carry = 0;
    for (i=0; i<(len1+len2); ++i)
    {
        int_res[i] += carry;
        carry = int_res[i]/10;
        int_res[i] %= 10;
    }
    
    i = len1+len2-1;
    while(int_res[i] == 0) --i;
    
    if (i<0) return "0";
    
    int len = i+2;
    char* res = (char*) malloc(len*sizeof(char));
    
    if (!res) return NULL;
    
    memset(res, 0, len);
    j = 0;
    for(; i>=0; --i)
    {
        res[j++] = int_res[i] + '0';
    }
    res[j]='\0';
    free(int_res);
    
    return res;
}


