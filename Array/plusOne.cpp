// Source : https://oj.leetcode.com/problems/plus-one/
// Author : ljin029
// Date   : 2017-04-17

/********************************************************************************** 
* 
* Given a non-negative number represented as an array of digits, plus one to the number.
* 
* The digits are stored such that the most significant digit is at the head of the list.
*               
**********************************************************************************/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1; // plus one
        vector<int> res(digits.size(), 0);
        
        // add operation starts from lowest significant digit
        for(int i=digits.size()-1; i>=0; --i){
            carry += digits[i];
            res[i] = carry%10;
            carry /= 10;
        }
        if(carry) res.insert(res.begin(), 1);
        return res;
    }
};


