#include <bits/stdc++.h> 
using namespace std;

int largestElement(vector<int> &arr, int n) {
    if (n == 0) {
        return INT_MIN;
    }

    int maxElement = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int result = largestElement(arr, n);
    cout << result;
    return 0;
}