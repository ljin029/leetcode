// Source : https://oj.leetcode.com/problems/path-sum-ii/
// Author :  ljin029
// Date   : 2017-11-06

/********************************************************************************** 
* 
* Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
* 
* For example:
* Given the below binary tree and sum = 22,
* 
*               5
*              / \
*             4   8
*            /   / \
*           11  13  4
*          /  \    / \
*         7    2  5   1
* 
* return
* 
* [
*    [5,4,11,2],
*    [5,8,4,5]
* ]
* 
*               
**********************************************************************************/

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> out;
        
        pathSum(root, sum, out, res);
        
        return res;
    }
    
    void pathSum(TreeNode* root, int sum, vector<int>& out, vector<vector<int>>& res)
    {
        if (!root) return;
        
        out.push_back(root->val);
        
        if (root->val==sum && !root->left && !root->right)
            res.push_back(out);
        
        pathSum(root->left, sum- root->val, out, res);
        pathSum(root->right, sum- root->val, out, res);
        out.pop_back();
    }
};


