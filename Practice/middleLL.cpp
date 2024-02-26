#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

int findMax(Node* head){
    int max = INT_MIN;
    while (head!=NULL){
        if (head->data > max){
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

Node* middle(Node *head){
    if (head==NULL){
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;

    while (fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    int n,x;
    Node *head = NULL;
    Node *tail = NULL;
    vector<int> arr;
    cout<<"Enter no. of elements: " << endl;
    cin >> n;
    cout<<"Enter the elements: "<<endl;
    for (int i=0;i<n;i++){
        cin>>x;
        Node *temp = new Node(x);
        if (head==NULL) {
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = tail->next;
        }
    }
    Node *result = middle(head);
    cout<< "Middle element is: " << result->data << endl;
    cout<< "Maximum element : " << findMax(head) << endl;
    return 0;
}
