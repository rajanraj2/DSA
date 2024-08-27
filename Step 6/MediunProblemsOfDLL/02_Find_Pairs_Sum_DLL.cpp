// Link - https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
// Find pairs with given sum in doubly linked list


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

// Alternate solution 2

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> result;
        if (head == nullptr || head->next == nullptr) return result;
        
        Node* left = head;
        Node* right = head;
        while (right->next) {
            right = right->next;
        }
        
        while (left->data < right->data) {
            int add = left->data + right->data;
            if (add == target) {
                result.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (add > target) {
                right = right->prev;
            }
            else {
                left = left->next;
            }
        }
        
        return result;
    }
};




// Alternate solution 1

// class Solution
// {
// public:
//     vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
//     {
//         // code here
//         vector<pair<int, int>> result;
//         if (head == nullptr || head->next == nullptr) return result;
        
//         Node* temp1 = head;
//         while (temp1) {
//             Node* temp2 = temp1->next;
//             while (temp2 != nullptr) {
//                 if (temp1->data + temp2->data == target) result.push_back({temp1->data, temp2->data});
//                 if (temp1->data + temp2->data > target) break;
//                 temp2 = temp2->next;
//             }
//             temp1 = temp1->next;
//         }
        
//         return result;
//     }
// };

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends