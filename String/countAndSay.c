// Source : https://oj.leetcode.com/problems/count-and-say/
// Author : ljin029
// Date   : 2017-04-06

/********************************************************************************** 
* 
* The count-and-say sequence is the sequence of integers beginning as follows:
* 1, 11, 21, 1211, 111221, ...
* 
* 1 is read off as "one 1" or 11.
* 11 is read off as "two 1s" or 21.
* 21 is read off as "one 2, then one 1" or 1211.
* 
* Given an integer n, generate the nth sequence.
* 
* Note: The sequence of integers will be represented as a string.
* 
*               
**********************************************************************************/

#define MAX_SIZE_CHARS 65535
char* countAndSay(int n) {
    if (!n) return NULL;
    else if (n==1) return "1";
    else if (n==2) return "11";
    
    char* res = (char*) malloc(MAX_SIZE_CHARS*sizeof(char));
    if(!res) return NULL;
    
    memset(res, 0, MAX_SIZE_CHARS);
    res[0] = '1', res[1] = '1';
    int i, j, len, ind, cnt, idx =2;
    char tmp[MAX_SIZE_CHARS] = {0};
    for (i=3; i<=n; i++)
    {
        res[idx++] = '#';
        len = strlen(res);
        cnt = 1;
        
        memset(tmp, 0, MAX_SIZE_CHARS);
        ind = 0;
        for(j=1; j<len; j++)
        {
            if (res[j] != res[j-1])
            {
                tmp[ind++] = cnt + '0';
                tmp[ind++] = res[j-1];
                cnt = 1;
            }
            else ++cnt;
        }
        memset(res, 0, idx);
        memcpy(res, tmp, ind);
        idx = ind;
    }
    
    return res;
}


