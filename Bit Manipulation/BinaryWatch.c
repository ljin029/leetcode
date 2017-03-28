// Source : https://leetcode.com/problems/binary-watch/
// Author : ljin029
// Date   : 2017-03-28

/*************************************************************************************** 
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 
 * LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are 
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", 
 * "0:16", "0:32"]
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid, it 
 * should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for example 
 * "10:2" is not valid, it should be "10:02".
 ***************************************************************************************/
 /**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
const uint8_t lookup[]     =      {  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,   
                                           1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,  
                                           1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,   
                                           2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,   
                                           1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,    
                                           2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,   
                                           2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,   
                                           3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,   
                                           1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,   
                                           2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,   
                                           2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,   
                                           3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,   
                                           2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,   
                                           3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,   
                                           3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,   
                                           4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};
                                         
int bitCount(uint32_t n) {
    register uint8_t *p = (uint8_t *)&n;

    return (lookup[p[0]] + lookup[p[1]] + lookup[p[2]] + lookup[p[3]]);

}
char** readBinaryWatch(int num, int* returnSize) {
    char** string;
    int i,j, cnt;
    char buf[10];
    
    string = (char*) malloc(720 * sizeof(char*));
    if (!string) return NULL;
    cnt = 0;
    for (i=0; i<12; i++)
    {
        for (j=0; j<60; j++)
        {
            if (bitCount(j|(i<<6)) == num)
            {
                memset(buf, 0, 10);
                if (j<10)
                {
                    sprintf(buf,"%d:0%d", i,j);
                    string[cnt] = (char*) malloc(strlen(buf) * sizeof(char));
                    strncpy(string[cnt], buf, strlen(buf));
                    //printf("string[%d]: %s\n", cnt, string[cnt]);
                }
                else
                {
                    sprintf(buf, "%d:%d", i,j);
                    string[cnt] = (char*) malloc(strlen(buf) * sizeof(char));
                    strncpy(string[cnt], buf, strlen(buf));
                    //printf("string[%d]: %s\n", cnt, string[cnt]);
                }
                cnt++;
            }
        }
    }
    *returnSize = cnt;
    
    return string;
}

