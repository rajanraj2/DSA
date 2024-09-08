// Link - https://leetcode.com/problems/implement-stack-using-queues/
// Implement Stack using Queues


class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int s = q.size();
        while (--s) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        int temp = q.front();
        return temp;
    }
    
    bool empty() {
        if (q.size() == 0)  return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */