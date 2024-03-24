#include <bits/stdc++.h>
using namespace std;

// int longestSuccessiveElements(vector<int>&a) {
//     int n = a.size();
//     if (n==0) return 0;
//     sort(a.begin(), a.end());
//     int lastSmaller = INT_MIN;
//     int cnt = 0;
//     int longest = 1;
//     for (int i=0; i<n; i++){
//         if (a[i] - 1 == lastSmaller){
//             cnt += 1;
//             lastSmaller = a[i];
//         }
//         else if (lastSmaller != a[i]){
//             cnt =  1;
//             lastSmaller = a[i];
//         }
//         longest = max(longest, cnt);
//     }
//     return longest;
// }

// Alternate method 2 : optimal under certain circumstances
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n==0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for (int i=0; i<n; i++) {
        st.insert(a[i]);
    }
    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            while (st.find(x+1) != st.end()) {
                x ++;
                cnt ++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main() {
    vector<int> a = {100, 4, 200, 1, 3, 2};
    cout << longestSuccessiveElements(a) << endl;
    return 0;
}
