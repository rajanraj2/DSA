#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
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

void print(Node* head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

Node* insertAtFirst(Node* list, int newValue) {
    Node* temp = new Node(newValue, list);
    return temp;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = constructLL(arr);
    head = insertAtFirst(head, 6);
    print(head);
    return 0;
}