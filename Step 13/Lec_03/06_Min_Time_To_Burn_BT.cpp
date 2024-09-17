// Link - https://www.geeksforgeeks.org/problems/burning-tree/1
// Burning Tree


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    Node* makeParent(Node* node, map<Node*, Node*>& parent, int target) {
        queue<Node*> q;
        q.push(node);
        Node* res;
        
        while (!q.empty()) {
            Node* top = q.front();
            q.pop();
            if (top->data == target) res = top;
            
            if (top->left) {
                parent[top->left] = top;
                q.push(top->left);
            }
            if (top->right) {
                parent[top->right] = top;
                q.push(top->right);
            }
        }
        return res;
    }
    
    int maxDistance(Node* node, map<Node*, Node*>& parent) {
        queue<Node*> q;
        q.push(node);
        map<Node*, bool> visited;
        visited[node] = true;
        int maxi = 0;
        
        while (!q.empty()) {
            int s = q.size();
            int flag = 0;
            for (int i = 0; i < s; i++) {
                Node* top = q.front();
                q.pop();
                
                if (top->left && !visited[top->left]) {
                    q.push(top->left);
                    visited[top->left] = true;
                    flag = 1;
                }
                
                if (top->right && !visited[top->right]) {
                    q.push(top->right);
                    visited[top->right] = true;
                    flag = 1;
                }
                
                if (parent[top] && !visited[parent[top]]) {
                    q.push(parent[top]);
                    visited[parent[top]] = true;
                    flag = 1;
                }
            }
            if (flag == 1) maxi++;
        }
        return maxi;
    }
    
    
    
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*, Node*> parent;
        Node* node = makeParent(root, parent, target);
        int maxi = maxDistance(node, parent);
        return maxi;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends