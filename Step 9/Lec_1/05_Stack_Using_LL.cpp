// Link - https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1
// Implement Stack using Linked List


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;

    StackNode(int a) {
        data = a;
        next = NULL;
    }
};


// } Driver Code Ends
class MyStack {
  private:
    StackNode *top;
    // StackNode* prev;

  public:
    void push(int x) {
        // code here
        StackNode* temp = new StackNode(x);
        temp->next = top;
        top = temp;
    }

    int pop() {
        // code here
        if (top == nullptr) return -1;
        int el = top->data;
        
        StackNode* temp = top;
        top = top->next;
        delete temp;
        
        return el;
        
    }

    MyStack() { top = NULL; }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        delete sq;
    }
}

// } Driver Code Ends