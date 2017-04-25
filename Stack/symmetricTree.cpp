// Source : https://oj.leetcode.com/problems/symmetric-tree/
// Author : ljin029
// Date   : 2017-04-25

/********************************************************************************** 
* 
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
* 
* For example, this binary tree is symmetric:
* 
*     1
*    / \
*   2   2
*  / \ / \
* 3  4 4  3
* 
* But the following is not:
* 
*     1
*    / \
*   2   2
*    \   \
*    3    3
* 
* Note:
* Bonus points if you could solve it both recursively and iteratively.
* 
*               
**********************************************************************************/

/*
*  The recursive solution:
*  1) If root==NULL, return true
*  2) Check if !left && right or left&&!right or left->val!=right->val, return false
*  3) Take the two nodes left->left and right->right, or left->right and right->left to check if they are mirror
*
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right){
        
        if (!left && !right) return true;
        if (left&&!right || !left&&right || left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};


