// Link - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
// Serialize and Deserialize Binary Tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string s = "";

        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            if (!top) s.append("#,");
            else {
                s.append(to_string(top->val) + ",");
                q.push(top->left);
                q.push(top->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;

        stringstream s(data);
        string str;
        getline(s, str, ','); 

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#") top->left = nullptr;
            else {
                top->left = new TreeNode(stoi(str));
                q.push(top->left);
            }

            getline(s, str, ',');
            if (str == "#") top->right = nullptr;
            else {
                top->right = new TreeNode(stoi(str));
                q.push(top->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));