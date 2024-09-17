// Link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
// Construct Binary Tree from Inorder and Postorder Traversal


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
    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd,
     vector<int>& postorder, int postStart, int postEnd, map<int, int>& mpp) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mpp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = helper(inorder, inStart, inRoot - 1, 
        postorder, postStart, postStart + numsLeft - 1, mpp);

        root->right = helper(inorder, inRoot + 1, inEnd, 
        postorder, postStart + numsLeft, postEnd - 1, mpp);

        return root;
     }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return nullptr;
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        TreeNode* root = helper(inorder, 0, inorder.size() - 1,
    postorder, 0, postorder.size() - 1, mpp);
        return root;
    }
};