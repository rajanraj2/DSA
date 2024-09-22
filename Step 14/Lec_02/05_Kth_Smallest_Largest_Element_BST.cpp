// Link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
// Kth Smallest Element in a BST


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
    void inorder(TreeNode* node, int& count, int k, int& result) {
        if (!node) return;

        inorder(node->left, count, k, result);
        count++;
        if (count == k) result = node->val;
        inorder(node->right, count, k, result);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int result = 0, count = 0;
        inorder(root, count, k, result);
        return result;
    }
};

// Can also do morris traversal for O(1) space complexity