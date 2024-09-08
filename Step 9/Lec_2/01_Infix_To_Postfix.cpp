// Link - https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
// Infix to Postfix


//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    bool isOperator(char ch) {
        if (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '(' || ch == ')') {
            return true;
        }
        return false;
    }
    
    int priority(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else return 1;
    }
    
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        string result = "";
        stack<char> st;
        
        for (char ch : s) {
            if (!isOperator(ch)) {
                result += ch;
            }
            else {
                if (ch == '(') {
                    st.push(ch);
                }
                else if (ch == ')') {
                    while (!st.empty() && st.top() != '(') {
                        result += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else {
                    while (!st.empty() && st.top() != '(' && priority(ch) <= priority(st.top())) {
                        result += st.top();
                        st.pop();
                    }
                    st.push(ch);
                }
            }
        }
        
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends