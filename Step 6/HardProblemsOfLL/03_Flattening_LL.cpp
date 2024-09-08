// Link - https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Flatten a multilevel linked list


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  private:
    Node* merge(Node* node1, Node* node2) {
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        
        while (node1 && node2) {
            if (node1->data < node2->data) {
                res->bottom = node1;
                res = node1;
                node1 = node1->bottom;
            }
            else {
                res->bottom = node2;
                res = node2;
                node2 = node2->bottom;
            }
            res->next = nullptr;
        }
        
        if (node1) res->bottom = node1;
        else res->bottom = node2;
        
        if (dummyNode->bottom) dummyNode->bottom->next = nullptr;
        return dummyNode->bottom;   
    }
    
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if (root == nullptr || root->next == nullptr) return root;
        
        Node* mergedHead = flatten(root->next);
        root = merge(root, mergedHead);
        return root;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends