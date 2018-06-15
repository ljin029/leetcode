// Source : https://leetcode.com/problems/binary-tree-paths/
// Author : Calinescu Valentin, Hao Chen
// Date   : 2015-10-23

/*************************************************************************************** 
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * For example, given the following binary tree:
 * 
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * 
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 * 
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test 
 * cases.
 *               
 ***************************************************************************************/

 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  * 	int val;
  * 	TreeNode *left;
  * 	TreeNode *right;
  * 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */
 class Solution {
 public:
	 vector<string> binaryTreePaths(TreeNode* root) {
		 vector<string> path;
		 
		 if(root) findPath(root, "", path);
		 return path;
	 }
	 void findPath(TreeNode* root, string out, vector<string>& path)
	 {
		 if(!root->left && !root->right) path.push_back(out + to_string(root->val));
		 if(root->left) findPath(root->left, out+to_string(root->val)+"->", path);
		 if(root->right) findPath(root->right, out+to_string(root->val)+"->", path);
	 }
 };

