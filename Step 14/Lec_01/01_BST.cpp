// Link - https://www.geeksforgeeks.org/problems/binary-search-trees/1
// Binary Search Trees


//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here]
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] >= arr[i]) {
                return false;
            }
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            nums[i] = k;
        }

        Solution ob;
        bool res = ob.isBSTTraversal(nums);
        if (res)
            cout << "True";
        else
            cout << "False";

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends