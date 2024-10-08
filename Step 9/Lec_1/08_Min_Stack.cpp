// Link - https://leetcode.com/problems/min-stack/
// Min Stack


class MinStack {
public:
    stack<long long> st;
    long long mini = LLONG_MAX;
    
    MinStack() {
        
    }
    
    void push(int val) {
        long long value = val;
        if (st.empty()) {
            mini = value;
            st.push(value);
        }
        else if (value > mini) {
            st.push(value);
        }
        else {
            st.push(2 * value - mini);
            mini = value;
        }
    }
    
    void pop() {
        if (st.empty()) return;
        if (st.top() < mini) {
            mini = 2 * mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if (st.empty()) return -1;
        if (mini < st.top()) {
            return st.top();
        }
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */