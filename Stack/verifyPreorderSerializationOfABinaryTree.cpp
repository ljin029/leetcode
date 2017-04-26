// Source : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// Author : ljin029
// Date   : 2017-04-26

/*************************************************************************************** 
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we encounter 
 * a non-null node, we record the node's value. If it is a null node, we record using a 
 * sentinel value such as #.
 * 
 *      _9_
 *     /   \
 *    3     2
 *   / \   / \
 *  4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 * 
 * For example, the above binary tree can be serialized to the string 
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 * 
 * Given a string of comma separated values, verify whether it is a correct preorder 
 * traversal serialization of a binary tree. Find an algorithm without reconstructing 
 * the tree.
 * 
 * Each comma separated value in the string must be either an integer or a character 
 * '#' representing null pointer.
 * 
 * You may assume that the input format is always valid, for example it could never 
 * contain two consecutive commas such as "1,,3".
 * 
 * Example 1:
 * "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Return true
 * Example 2:
 * "1,#"
 * Return false
 * Example 3:
 * "9,#,#,1"
 * Return false
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/

/*
 *	The solution:
 *	1) Using stringstream to split the string between "," and store the strings into vector
 *    2) the number of digits is 1 less than the number of "#"
 *    3) the last string must be "#"
 *    4) Regardless the last char of "#", using one counter to increment if digit or decrement if "#"
 *    5) Traverse the vector, if counter == 0 and the last string is "#" return true;
 *    6) If counter==0 and we need to decrement, return false
 *
 */

 class Solution {
 public:
	 bool isValidSerialization(string preorder) {
		 if (preorder.empty()) return false;
		 stringstream ss(preorder);
		 vector<string> v;
		 string tmp;
		 
		 while(getline(ss, tmp, ',')) v.push_back(tmp);
		 int cnt = 0;
		 for(int i=0; i<v.size()-1; ++i){
			 if (v[i]=="#"){
				 if(cnt==0) return false;
				 --cnt;
			 }else{
				 ++cnt;
			 }
		 }
		 
		 return cnt!=0?false:v.back()=="#";
	 }
 };


