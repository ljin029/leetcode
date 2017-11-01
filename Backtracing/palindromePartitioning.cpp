// Source : https://oj.leetcode.com/problems/palindrome-partitioning/
// Author : ljin029
// Date   : 2017-10-31

/********************************************************************************** 
* 
* Given a string s, partition s such that every substring of the partition is a palindrome.
* 
* Return all possible palindrome partitioning of s.
* 
* For example, given s = "aab",
* 
* Return
* 
*   [
*     ["aa","b"],
*     ["a","a","b"]
*   ]
* 
*               
**********************************************************************************/


// DFS - Deepth First Search
//    
//   For example: "aaba"
//    
//                     +------+           
//              +------| aaba |-----+     
//              |      +------+     |     
//            +-v-+              +-v--+  
//            | a |aba           | aa |ba
//        +---+---+--+           +--+-+  
//        |          |              |    
//      +-v-+     +--v--+         +-v-+  
//      | a |ba   | aba |\0       | b |a 
//      +-+-+     +-----+         +-+-+  
//        |        a, aba           |    
//      +-v-+                     +-v-+  
//      | b |a                    | a |\0
//      +-+-+                     +---+  
//        |                      aa, b, a
//      +-v-+                            
//      | a |\0                          
//      +---+                            
//    a, a, b, a                         

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        partitionDFS(s, 0, out, res);
        return res;
    }
    void partitionDFS(string s, int start, vector<string> &out, vector<vector<string>> &res) {
        if (start == s.size()) {
            res.push_back(out);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            
            if (isPalindrome(s, start, i)) {
                out.push_back(s.substr(start, i - start + 1));
                partitionDFS(s, i + 1, out, res);
                out.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
};


