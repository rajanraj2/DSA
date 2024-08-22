// Link - https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1
// Doubly Linked List Node structure


void addNode(Node *head, int pos, int data)
{
   // Your code here
   
   
   if (pos == 0) {
       Node* newNode = new Node(data);
       newNode->next = head->next;
       if (head != nullptr) {
            newNode->prev = head;
            if (head->next != nullptr) {
                head->next->prev = newNode;
            }
            head->next = newNode;
       }
       return;
   }

   Node* temp = head;
   int count = 0;
    
   while (temp != nullptr && count < pos ) {
       temp = temp->next;
       count++;
   }
   
   if (temp == nullptr) return;
   
   if (temp->next == nullptr) {
       temp->next = new Node(data);
       temp->next->prev = temp;
   }
   else {
       Node* newNode = new Node(data);
       newNode->prev = temp;
       newNode->next = temp->next;
       temp->next = newNode;
       newNode->next->prev = newNode;
   }
}