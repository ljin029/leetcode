// Source : https://oj.leetcode.com/problems/add-binary/
// Author : ljin029
// Date   : 2017-04-10

/********************************************************************************** 
* 
* Given two binary strings, return their sum (also a binary string).
* 
* For example,
* a = "11"
* b = "1"
* Return "100".
* 
*               
**********************************************************************************/

char* addBinary(char* a, char* b) {
    if (!a) return b;
    else if (!b) return a;
    
    int i = strlen(a);
    int j = strlen(b);
    int c = 0;
    int int_len = i>j? i:j;
    // One more for carry
    int_len += 1;
    int* int_res = (int*) malloc(int_len * sizeof(int));
    
    if (!int_res) return NULL;
    
    int len = int_len;
    memset(int_res, 0, len);
    len -= 1,  i -= 1, j -= 1;
    while(i>=0 || j>=0 || c==1 || len>=0)
    {
        c += i>=0?(a[i--]-'0'):0;
        c += j>=0?(b[j--]-'0'):0;
        int_res[len--] = (c%2);
        c /= 2;
    }
    
    len = 0;
    // Remove leading '0'
    while(int_res[len]== 0 && len<int_len) ++len;
    // If all '0's, return '0'
    if (len == int_len) return "0";
    
    int res_len = int_len - len;
    // One more for '\0'
    char* res = (char*) malloc((res_len+1)*sizeof(char));
    
    if (!res) return NULL;
    
    i=0;
    memset(res, 0, res_len);
    for(i=0; i<res_len; i++)
      res[i] = int_res[len + i] + '0';
    res[i] = '\0';
    
    free(int_res);
    return res;
}

