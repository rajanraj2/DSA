#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

Node* constructLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

class Solution {
public:
    void deleteNode(Node* node) {
        Node* nxt =  node -> next;
        node -> data = nxt -> data;
        node -> next = nxt -> next;
    }
};

void print(Node* head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = constructLL(arr);
    Solution sol;
    sol.deleteNode(head -> next -> next);
    print(head);
    return 0;
}
