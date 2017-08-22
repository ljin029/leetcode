// Source : https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author : ljin029
// Date   : 2017-08-22

/********************************************************************************** 
* 
* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*               
**********************************************************************************/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right){
        if (left > right) return NULL;
        
        int mid = (left + right) / 2;
        TreeNode *curr = new TreeNode(nums[mid]);
        curr->left = sortedArrayToBST(nums, left, mid-1);
        curr->right = sortedArrayToBST(nums, mid+1, right);
        
        return curr;
    }
}; 

