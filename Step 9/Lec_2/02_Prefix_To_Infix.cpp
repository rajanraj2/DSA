// Link - https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1
// Prefix to Infix


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool isOperator(char ch) {
        return (ch == '^' || ch == '%' || ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '(' || ch == ')');
    }
    
    int priority(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else return 1;
    }
    
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        string result = "";
        stack<string> ans;
        
        for (int i = pre_exp.size(); i >= 0; i--) {
            if (!isOperator(pre_exp[i])) {
                string val = "";
                val += pre_exp[i];
                ans.push(val);
            }
            else {
                string t1 = ans.top();
                ans.pop();
                string t2 = ans.top();
                ans.pop();
                string val = "(" + t1 + pre_exp[i] + t2 + ")";
                ans.push(val);
            }
        }
        
        return ans.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends