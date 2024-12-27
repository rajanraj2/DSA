#include <bits/stdc++.h>
using namespace std;

void f(int i, vector<int> &temp, int n, vector<int> arr, int sum, int& k) {
    if (i >= n) {
        if (sum == k) {
            for (int j = 0; j < temp.size(); j++) cout << temp[j] << " ";
            cout << endl;
        }
        return;
    }
    temp.push_back(arr[i]);
    sum += arr[i];
    f(i + 1, temp, n, arr, sum, k); // take
    temp.pop_back();
    sum -= arr[i];
    f(i + 1, temp, n, arr, sum, k); // not take
}

int main() {
    vector<int> arr = {3, 1, 2};
    vector<int> temp;
    int k = 3;
    f(0, temp, arr.size(), arr, 0, k);
    return 0;
}