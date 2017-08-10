// Source : https://oj.leetcode.com/problems/edit-distance/
// Author : Hao Chen
// Date   : 2014-08-22

/********************************************************************************** 
* 
* Given two words word1 and word2, find the minimum number of steps required to 
* convert word1 to word2. (each operation is counted as 1 step.)
* 
* You have the following 3 operations permitted on a word:
* 
* a) Insert a character
* b) Delete a character
* c) Replace a character
* 
*               
**********************************************************************************/

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int> > distances(len1 + 1, vector<int> (len2 + 1, 0));
        
        int editDistance = getEditDistance(word1, word2, distances, len1, len2);
        
        return editDistance;
    }
    
    int getEditDistance(string str1, string str2, vector<vector<int>>& distances, int len1, int len2)
    {
        for (int i=0; i<len1+1; ++i)
            distances[i][0]=i;
        
        for (int j=0; j<len2+1; ++j)
            distances[0][j]=j;
        
        for (int i=1; i<len1+1; ++i){
            for (int j=1; j<len2+1; ++j){
                if (str1[i-1] == str2[j-1]){
                    distances[i][j] = distances[i-1][j-1];
                }else{
                    int del = distances[i][j-1]+1;
                    int ins = distances[i-1][j]+1;
                    int sub = distances[i-1][j-1]+1;
                    
                    distances[i][j] = min(del, ins, sub);
                }
            }
        }
        
        return distances[len1][len2];
    }
    
    int min(int n1, int n2, int n3)
    {
        int less = (n1 < n2? n1:n2);
        
        return (less < n3? less: n3);
    }
};


