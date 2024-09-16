// Link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
// Vertical Order Traversal of a Binary Tree


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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        map<int, map<int, multiset<int>>> mpp;  
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            TreeNode* node = top.first;
            int x = top.second.first, y = top.second.second;

            mpp[x][y].insert(node->val);
            if (node->left) q.push({node->left, {x - 1, y + 1}});
            if (node->right) q.push({node->right, {x + 1, y + 1}});
        }

        for (auto it : mpp) {
            vector<int> col;
            for (auto iter : it.second) {
                col.insert(col.end(), iter.second.begin(), iter.second.end());
            }
            result.push_back(col);
        }

        return result;
    }
};