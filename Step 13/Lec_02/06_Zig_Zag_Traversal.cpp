// Link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
// Binary Tree Zigzag Level Order Traversal


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        int check = 1;

        while (!q.empty()) {
            int s = q.size();
            vector<int> ans(s);
            for (int i = 0; i < s; i++) {
                TreeNode* top = q.front();
                q.pop();
                int index = (check == 1) ? i : s - i - 1;
                ans[index] = top->val;

                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            result.push_back(ans);
            check = (check + 1) % 2;    
        }
        return result;
    }
};