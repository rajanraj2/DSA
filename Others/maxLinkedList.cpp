#include <iostream>
#include <climits>
using namespace std;

struct Node {
    public :
    int data;
    Node* next;
    Node (int data){
        this->data = data;
        next = NULL;
    }
};

int findMax(Node *head){
    int max = INT_MIN;
    while (head!=NULL){
        if (head->data > max){
            max = head->data;
        }
        head = head->next;
        // else {
        //     return -1;
        // }
    }
    return max;
}

int main(){
    int x;
    Node* head = NULL;
    Node *tail = NULL;
    cout<< "Enter 5 elements :" << endl;
    for (int i=0; i<5; i++){
        cin>>x;
        Node* temp = new Node(x);
        if (head == NULL){
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = tail->next;
        }
    }
    cout<< "Maximum element : " << findMax(head) << endl;
    return 0;
}