// Source : https://oj.leetcode.com/problems/simplify-path/
// Author : ljin029
// Date   : 2017-04-25

/********************************************************************************** 
* 
* Given an absolute path for a file (Unix-style), simplify it.
* 
* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
* 
* 
* Corner Cases:
* 
* Did you consider the case where path = "/../"?
* In this case, you should return "/".
* Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
* In this case, you should ignore redundant slashes and return "/home/foo".
* 
*               
**********************************************************************************/

/*
*  The solution:
*  1) traverse the whole string to record each dir name
*  2) two special case:
        a) if "..", pop the previous push string
        b) if ".", skip it and do nothing
*
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string res, tmp;
        
        stringstream ss(path);
        // store ss into tmp until "/"
        while(getline(ss, tmp, '/')){
            if(tmp=="" or tmp==".") continue; // skip '.'
            if(tmp==".." && !v.empty()) v.pop_back();  // pop the previous push
            else if(tmp != "..") v.push_back(tmp);
        }
        for(auto s:v){
            res += "/" + s;
        }
        
        return res.empty()?"/" : res;
    }
};


