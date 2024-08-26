// Link - https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
// Add 1 to a number represented as linked list


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/
// Method 1 

class Solution {
  private:
    Node* reverseLL(Node* node) {
        if (node == nullptr || node->next == nullptr) return node;
        
        Node* newHead = reverseLL(node->next);
        Node* front = node->next;
        front->next = node;
        node->next = nullptr;
        return newHead;
    }
    
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        head = reverseLL(head);
        
        int carry = 1;
        Node* temp = head;
        while (temp) {
            temp->data += carry;
            if (temp->data < 10) {
                carry = 0;
                break;
            }
            else {
                temp->data = 0;
                carry = 1;
            }
            temp = temp->next;
        }
        head = reverseLL(head);
        if (carry == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};



// Method 2 - optimised

// class Solution {
//   private:
//     int helper(Node* temp) {
//         if (temp == nullptr) return 1;
        
//         int carry = helper(temp->next);
//         temp->data = temp->data + carry;

//         if (temp->data < 10) {
//             return 0;
//         }
//         temp->data = 0;
//         return 1;
//     }
    
    
//   public:
//     Node* addOne(Node* head) {
//         // Your Code here
//         // return head of list after adding one
//         int carry = helper(head);
//         if (carry == 1) {
//             Node* newNode = new Node(1);
//             newNode->next = head;
//             head = newNode;
//         }
//         return head;
        
//     }
// };

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends