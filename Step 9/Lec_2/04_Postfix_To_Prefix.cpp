// Link - https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1
// Post fix to Prefix conversion


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
    string postToPre(string post_exp) {
        // Write your code here
        stack<string> ans;
        
        for (int i = 0; i < post_exp.size(); i++) {
            if (!isOperator(post_exp[i])) {
                string val = "";
                val += post_exp[i];
                ans.push(val);
            }
            else {
                string t1 = ans.top();
                ans.pop();
                string t2 = ans.top();
                ans.pop();
                string val = post_exp[i] + t2 + t1;
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends