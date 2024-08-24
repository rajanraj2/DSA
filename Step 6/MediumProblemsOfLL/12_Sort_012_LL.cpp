// Link - https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
// Sort a linked list of 0s, 1s and 2s


/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        if (head == nullptr || head->next == nullptr) return head;
        
        Node* temp = head;
        Node* zero = new Node(-1);
        Node* one = new Node(-1);
        Node* two = new Node(-1);
        
        Node* zeroHead = zero;
        Node* oneHead = one;
        Node* twoHead = two;
        
        while (temp) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            }
            else if (temp->data == 2) {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        
        if (oneHead->next != nullptr) {
            zero->next = oneHead->next;
        }
        else {
            zero->next = twoHead->next;
        }
        one->next = twoHead->next;
        two->next = nullptr;
        
        return zeroHead->next;
    }
};