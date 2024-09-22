// Link - https://leetcode.com/problems/delete-node-in-a-bst/description/
// Delete Node in a BST


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
    TreeNode* helper(TreeNode* node) {
        if (!node->left) return node->right;
        else if (!node->right) return node->left;

        TreeNode* rightChild = node->right;
        TreeNode* lastRight = findLastRight(node->left);
        lastRight->right = rightChild;
        return node->left;
    }

    TreeNode* findLastRight(TreeNode* node) {
        while (node->right) {
            node = node->right;
        }
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val == key) return helper(root);

        TreeNode* dummy = root;
        while (root) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};