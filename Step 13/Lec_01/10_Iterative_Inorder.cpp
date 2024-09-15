// Link - https://leetcode.com/problems/binary-tree-inorder-traversal/
// Binary Tree Inorder Traversal


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (true) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            }
            else {
                if (st.empty() == true) break;
                node = st.top();
                st.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }

        return result;
    }
};


// Alternate method - recursion

// class Solution {
// private:
//     void helper(TreeNode* node, vector<int>& result) {
//         if (node == nullptr) return;

//         helper(node->left, result);
//         result.push_back(node->val);
//         helper(node->right, result);
//     }

// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         helper(root, result);
//         return result;
//     }
// };