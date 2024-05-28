//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool comp(Item val1, Item val2) {
    double r1 = (double)val1.value/val1.weight; 
    double r2 = (double)val2.value/val2.weight; 
    return r1 > r2;
}
// bool comp(Item val1, Item val2) {
//     if (val1.value/val1.weight >= val2.value/val2.weight) return true;
//     return false;
// }

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        double maxValue = 0;
        int remCapacity = w;
        
        sort(arr, arr + n, comp);
        for (int i=0; i<n; i++) {
            if (arr[i].weight <= remCapacity) {
                maxValue += arr[i].value;
                remCapacity -= arr[i].weight;
            }
            else {
                double fraction = remCapacity * (double)arr[i].value/arr[i].weight;
                maxValue += fraction;
                remCapacity = 0;
                break;
            }
        }
        return maxValue;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends