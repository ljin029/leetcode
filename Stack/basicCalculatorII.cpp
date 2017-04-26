// Source : https://leetcode.com/problems/basic-calculator-ii/
// Author : ljin029
// Date   : 2017-04-26

/********************************************************************************** 
 * 
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces  . 
 * The integer division should truncate toward zero.
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * 
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
 * 
 * Note: Do not use the eval built-in library function.
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 **********************************************************************************/

/*
*  The solution:
*  Using stack to store the numbers which are negative or positive while operator is "+" or "-", 
*  traversing the string finds the operator  "*" or "/", and pop up the number and do operation 
*  with the current number and push the result into stack again.
*  Finally, add all the numbers poped from the stack.
*
*/


class Solution {
public:
    int calculate(string s) {
        stack<int> myCal;
        int res=0, d=0;
        char sign = '+';
        
        for(int i=0; i<s.size(); ++i){
            if (s[i]>='0'){
                d = d*10 + s[i] - '0';
            }
            if (s[i]<'0'&&s[i]!=' ' || i==s.size()-1){
                if (sign == '+') myCal.push(d);
                if (sign == '-') myCal.push(-d);
                if (sign== '*' || sign=='/'){
                    int tmp = sign=='*'?myCal.top()*d : myCal.top()/d;
                    myCal.pop();
                    myCal.push(tmp);
                }
                sign = s[i];
                d = 0;
            }
        }
        
        while(!myCal.empty()){
            res += myCal.top();
            myCal.pop();
        }
        return res;
        
    }
};

