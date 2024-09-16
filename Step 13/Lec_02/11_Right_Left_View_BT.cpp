// Link - https://leetcode.com/problems/binary-tree-right-side-view/
// Binary Tree Right Side View


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
    void helper(TreeNode* node, int level, vector<int>& result) {
        if (!node) return;
        if (result.size() == level) result.push_back(node->val);

        if (node->right) helper(node->right, level + 1, result);
        if (node->left) helper(node->left, level + 1, result);
        return;
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int level = 0;
        if (root == nullptr) return result;

        helper(root, level, result);
        return result;
    }
};


// Alternate method : iterative 

// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> result;
//         if (!root) return result;
//         queue<TreeNode*> q;
//         q.push(root);

//         while (!q.empty()) {
//             int s = q.size();
//             int ans;
//             for (int i = 0; i < s; i++) {
//                 TreeNode* top = q.front();
//                 q.pop();
//                 if (top->left) q.push(top->left);
//                 if (top->right) q.push(top->right);
//                 ans = top->val;
//             }
//             result.push_back(ans);
//         }

//         return result;
//     }
// };