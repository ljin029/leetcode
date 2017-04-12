// Source : https://leetcode.com/problems/integer-to-english-words/
// Author : ljin029
// Date   : 2017-04-12

/*************************************************************************************** 
 *
 * Convert a non-negative integer to its english words representation. Given input is 
 * guaranteed to be less than 231 - 1.
 * 
 * For example,
 * 
 * 123 -> "One Hundred Twenty Three"
 * 12345 -> "Twelve Thousand Three Hundred Forty Five"
 * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 * 
 *   Did you see a pattern in dividing the number into chunk of words? For example, 123 
 * and 123000.
 *
 *   Group the number by thousands (3 digits). You can write a helper function that 
 * takes a number less than 1000 and convert just that chunk to words.
 *
 *   There are many edge cases. What are some good test cases? Does your code work with 
 * input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
 *               
 ***************************************************************************************/

#define NUM_OF_CHARS  2014
#define NUM_OF_GROUP  4
void convertHelper(char* dst, int num)
{
    char* v1[20] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    char* v2[10] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    
    int a=num/100, b=num%100, c=b%10;
    if (a>0){
        strcat(dst, v1[a]);
        strcat(dst, "Hundred ");
    }
    if (b<20){
        strcat(dst, v1[b]);
    }
    else{
        strcat(dst, v2[b/10]);
        if (c){
            strcat(dst, v1[c]);
        }
    }
}

char* numberToWords(int num) {
    
    if (!num) return "Zero";
	
    int int_arr[NUM_OF_GROUP] = {0}; // 4 groups for 2^31 - 1
    char* v[NUM_OF_GROUP] = {"Billion ", "Million ", "Thousand ", "" };
    char int_words[NUM_OF_CHARS] = {0};
    
    int i;
    for(i=NUM_OF_GROUP-1;i>=0;--i)
    {
        int_arr[i]=num%1000;
        num /= 1000;
    }
    
    for(i=0; i<NUM_OF_GROUP; ++i)
    {
        if (int_arr[i]){
           convertHelper(int_words, int_arr[i]);
           strcat(int_words, v[i]);
        }
    }
    
    int len = strlen(int_words);
    char* res = (char*) malloc(len*sizeof(char));
    
    if (!res) return NULL;
    
    memset(res, 0, len);
    // Remove the last char of space
    memcpy(res, int_words, (len-1));

    return res;
}

