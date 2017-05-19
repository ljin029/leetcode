// Source : https://leetcode.com/problems/count-complete-tree-nodes/
// Author : ljin029
// Date   : 2017-05-18

/********************************************************************************** 
 * 
 * Given a complete binary tree, count the number of nodes.
 * 
 * Definition of a complete binary tree from Wikipedia:
 * http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees
 *
 * In a complete binary tree every level, except possibly the last, is completely filled, 
 * and all nodes in the last level are as far left as possible. 
 * It can have between 1 and 2^h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        TreeNode* pleft = root, *pright = root;
        
        int lh = 0;
        while(pleft){
            ++lh;
            pleft = pleft->left;
        }
        
        int rh = 0;
        while(pright){
            ++rh;
            pright = pright->right;
        }
        
        if (lh == rh) return pow(2, lh) - 1;
        
        return countNodes(root->right) + countNodes(root->left) + 1;
    }
};

