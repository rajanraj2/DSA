#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int>&a) {
    int n = a.size();
    vector<int> result;
    int leader = INT_MIN;
    for (int i=n-1; i>=0; i--) {
        if (a[i] > leader) {
            result.push_back(a[i]);
            leader = a[i];
        }
    }
    return result;
}

int main() {
    vector<int> a = {16, 17, 4, 3, 5, 2};
    vector<int> result = superiorElements(a);
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}