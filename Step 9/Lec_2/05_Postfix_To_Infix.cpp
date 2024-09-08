// Link - https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1
// Post fix to Infix conversion


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
//   private:
//     bool isOperator(char ch) {
//         return (ch == '^' || ch == '%' || ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '(' || ch == ')');
//     }
    
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        
        for (int i = 0; i < exp.size(); i++) {
            
            
            // if (!isOperator(exp[i])) {
            if ((exp[i]>='A'&&exp[i]<='Z') ||(exp[i]>='a'&&exp[i]<='z')||(exp[i]>='0'&&exp[i]<='9')) {
                // string val = "";
                // val += exp[i];
                st.push(string(1, exp[i]));
            }
            else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                st.push("(" + t2 + exp[i] + t1 + ")");
            }
        }
        
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends