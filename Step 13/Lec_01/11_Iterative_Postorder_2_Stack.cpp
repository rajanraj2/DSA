// Link - https://leetcode.com/problems/binary-tree-postorder-traversal/
// Binary Tree Postorder Traversal


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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        TreeNode* node = root;

        while (!st1.empty()) {
            TreeNode* top = st1.top();
            st1.pop();
            st2.push(top);
            if (top->left) st1.push(top->left);
            if (top->right) st1.push(top->right);
        }

        while (!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
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
//         helper(node->right, result);
//         result.push_back(node->val);
//     }
    
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         helper(root, result);
//         return result;
//     }
// };