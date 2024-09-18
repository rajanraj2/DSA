// Link - https://leetcode.com/problems/search-in-a-binary-search-tree/description/
// Search in a Binary Search Tree


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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;

        while (curr != nullptr && curr->val != val) {
            if (curr->val > val) curr = curr->left;
            else if (curr->val < val) curr = curr->right;
        }

        return curr;
    }
};