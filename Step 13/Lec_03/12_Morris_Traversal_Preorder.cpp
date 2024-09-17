// Link - https://leetcode.com/problems/binary-tree-preorder-traversal/description/
// Binary Tree Preorder Traversal


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


// Alternate method : iterative

// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         if (root == nullptr) return result;
//         stack<TreeNode*> st;
//         st.push(root);

//         while (!st.empty()) {
//             root =  st.top();
//             st.pop();
//             result.push_back(root->val);
//             if (root->right) st.push(root->right);
//             if (root->left) st.push(root->left);
//         }

//         return result;
//     }
// };


// Alternate method : recursion

// class Solution {
// private:
//     void helper(TreeNode* root, vector<int>& result) {
//         if (root == nullptr) return;

//         result.push_back(root->val);
//         helper(root->left, result);
//         helper(root->right, result);
//     }
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         helper(root, result);
//         return result;
//     }
// };


// Alternate method : morris traversal

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if (!root) return preorder;

        TreeNode* curr = root;

        while (curr) {
            if (curr->left == nullptr) {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return preorder;
    }
};