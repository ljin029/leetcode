// Source : https://oj.leetcode.com/problems/binary-search-tree-iterator/
// Author : ljin029
// Date   : 2017-04-25

/********************************************************************************** 
 * 
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 * 
 * Calling next() will return the next smallest number in the BST.
 * 
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

/*
*  The solution:
*  left < root < right, using stack to store the left tree for the smallest number in the BST.
*
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> st;
    void push_left(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        push_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty()) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *p = st.top();
        st.pop();
        push_left(p->right);
        return p->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

