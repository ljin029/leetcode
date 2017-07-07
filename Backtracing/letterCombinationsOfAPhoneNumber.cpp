// Source : https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : ljin029
// Date   : 2016-06-29

/********************************************************************************** 
* 
* Given a digit string, return all possible letter combinations that the number could represent.
* 
* A mapping of digit to letters (just like on the telephone buttons) is given below.
* 
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
* 
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
* 
*               
**********************************************************************************/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size()==0) return res;
        
        string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        res.push_back("");
        for (int i=0; i<digits.size(); ++i)
        {
            int n = res.size();
            string str = dict[digits[i]-'0'];
            if (str.empty()) continue;
            for(int j=0; j<n; ++j)
            {
                string tmp = res.front();
                res.erase(res.begin());
                for(int k=0; k<str.size();++k)
                {
                    res.push_back(tmp+str[k]);
                }
            }
        }
        return res;
    }
};



