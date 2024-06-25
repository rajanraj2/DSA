#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &arr, int start, int end) {
    if (start >= end) {
        return;
    }
    swap(arr[start], arr[end]);
    f(arr, start + 1, end - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    f(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}