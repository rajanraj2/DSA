// Link - https://leetcode.com/problems/balanced-binary-tree/description/
// Balanced Binary Tree


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
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;

        int lh = dfs(node->left);
        int rh = dfs(node->right);

        if (lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};