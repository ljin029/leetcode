// Source : https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
// Author : Hao Chen
// Date   : 2014-06-22

/******************************************************************************
**** 
* 
* Given a binary tree, find its minimum depth.
* 
* The minimum depth is the number of nodes along the shortest path from the 
root node 
* down to the nearest leaf node.
*               
*******************************************************************************
***/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution {
 public:
     int minDepth(TreeNode* root) {
         if(root == NULL) return 0;
         if(root->left == NULL && root->right == NULL) return 1;
         
         if(root->left == NULL) return 1 + minDepth(root->right);
         else if(root->right == NULL) return 1 + minDepth(root->left);
         else return (1 + min(minDepth(root->right), minDepth(root->left)));
     }
 };

