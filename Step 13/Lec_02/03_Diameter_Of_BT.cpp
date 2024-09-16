// Link - https://leetcode.com/problems/diameter-of-binary-tree/description/
// Diameter of a Binary Tree


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
    int dfs(TreeNode* node, int& maxi) {
        if (node == nullptr) return 0;

        int lh = dfs(node->left, maxi);
        int rh = dfs(node->right, maxi);

        maxi = max(maxi, lh + rh);
        return max(lh, rh) + 1; 
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
};