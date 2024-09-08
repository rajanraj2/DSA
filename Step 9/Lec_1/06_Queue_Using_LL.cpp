// Link - https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1
// Implement Queue using Linked List


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }

// } Driver Code Ends


/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.

void MyQueue:: push(int x)
{
        // Your Code
        QueueNode* newNode = new QueueNode(x);
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = rear->next;
        }
        
        
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code  
        if (front == nullptr) return -1;
        int el = front->data;
        
        QueueNode* deleteNode = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete deleteNode;
        
        return el;
}