#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(T data, T* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node<int>* constructLL(vector<int>& arr) {
    Node<int>* head = new Node<int>(arr[0]);
    Node<int>* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node<int>* temp = new Node<int>(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int searchInLinkedList(Node<int> *head, int k) {
    Node<int>* temp = head;
    while (temp) {
        if (temp->data == k) return 1;
        temp = temp->next;
    }
    return 0;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node<int>* head = constructLL(arr);
    cout << searchInLinkedList(head, 3) << endl;
    return 0;
}