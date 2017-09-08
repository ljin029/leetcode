// Source : https://oj.leetcode.com/problems/longest-common-prefix/
// Author : ljin029
// Date   : 2017-09-08

/********************************************************************************** 
* 
* Write a function to find the longest common prefix string amongst an array of strings.
* 
* Input  : {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
* Output : "gee"
* Solution: Divide and conquer algorithm
* The idea of the algorithm comes from the associative property of LCP operation. We notice that :
* LCP(S1...Sn) = LCP(LCP(S1,Smid), LCP(Smid+1, Sn)), where mid = (i+j)/2
**********************************************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0)
            return "";
        
        return lcp(strs, 0, strs.size()-1);
    }
    
    string lcp(vector<string>& strs, int l, int r)
    {
        if (l==r) return strs[l];
        
        int mid = (l + r)/2;
        string left = lcp(strs, l, mid);
        string right = lcp(strs, mid+1, r);
        return commonPrefix(left, right);
    }
    
    string commonPrefix(string left, string right)
    {
        int min = left.size()<right.size()?left.size():right.size();
        
        for (int i=0; i<min; ++i)
        {
            if (left[i]!=right[i])
                return left.substr(0, i);
        }
        return left.substr(0, min);
    }
    
    
};



