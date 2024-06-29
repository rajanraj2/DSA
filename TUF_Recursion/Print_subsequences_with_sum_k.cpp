#include <bits/stdc++.h>
using namespace std;

void f(int i, vector<int> &temp, int n, vector<int> arr) {
    if (i >= n) {
        for (int j = 0; j < temp.size(); j++) {
            sum += temp[j];
            cout << temp[j] << " ";
        }
        cout << endl;
        return;
    }
    temp.push_back(arr[i]);
    f(i + 1, temp, n, arr); // take
    temp.pop_back();
    f(i + 1, temp, n, arr); // not take
}

int main() {
    vector<int> arr = {3, 1, 2};
    vector<int> temp;
    f(0, temp, arr.size(), arr);
    return 0;
}