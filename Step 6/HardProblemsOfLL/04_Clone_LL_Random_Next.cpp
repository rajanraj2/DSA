// Link - https://leetcode.com/problems/copy-list-with-random-pointer/description/
// Copy List with Random Pointer


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        temp = head;
        while (temp) {
            if (temp->random) temp->next->random = temp->random->next;
            else temp->next->random = nullptr;
            temp = temp->next->next;
        }

        temp = head;
        Node* newHead = temp->next;
        while (temp) {
            Node* ogNode = temp->next->next;
            if (temp->next->next) temp->next->next = temp->next->next->next;
            temp->next = ogNode;
            temp = temp->next;
        }

        return newHead;
    }
};