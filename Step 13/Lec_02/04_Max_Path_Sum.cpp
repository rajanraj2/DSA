// Link - https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Max Path Sum


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
        if (!node) return 0;

        int left = max(0, dfs(node->left, maxi));
        int right = max(0, dfs(node->right, maxi));

        maxi = max(maxi, left + right + node->val);

        return max(left, right) + node->val; 
    }

public:
    int maxPathSum(TreeNode* root) {
        int path = INT_MIN;
        dfs(root, path);
        return path;
    }
}; 