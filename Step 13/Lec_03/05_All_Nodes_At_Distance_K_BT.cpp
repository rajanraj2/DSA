// Link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// All nodes distance k in binary tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void makeParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& mpp) {
        queue<TreeNode*> q;
        q.push(node);

        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            if (top->left) {
                mpp[top->left] = top;
                q.push(top->left);
            }

            if (top->right) {
                mpp[top->right] = top;
                q.push(top->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        unordered_map<TreeNode*, TreeNode*> parent;
        makeParent(root, parent);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        int level = 0;

        queue<TreeNode*> q;
        q.push(target);

        while (!q.empty()) {
            int s = q.size();
            if (level++ == k) break;


            for (int i = 0; i < s; i++) {
                TreeNode* top = q.front();
                q.pop();

                if (top->left && !visited[top->left]) {
                    q.push(top->left);
                    visited[top->left] = true;
                }

                if (top->right  && !visited[top->right]) {
                    q.push(top->right);
                    visited[top->right] = true;
                }

                if (parent[top] && !visited[parent[top]]) {
                    q.push(parent[top]);
                    visited[parent[top]] = true;
                }
            }
        }

        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};

