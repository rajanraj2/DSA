// Link - https://leetcode.com/problems/validate-binary-search-tree/description/
// Validate Binary Search Tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool helper(TreeNode* root, long long start, long long end) {
        if (!root) return true;

        if (root->val <= start || root->val >= end)  return false; 

        return helper(root->left, start, root->val) && helper(root->right, root->val, end); 
    }

public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};