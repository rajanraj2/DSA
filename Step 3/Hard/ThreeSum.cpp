#include <bits/stdc++.h>
using namespace std;

// Alternate method 1 : brute 
// vector<vector<int>> triplet(int n, vector<int> &arr)
// {
//     set<vector<int>> st;
//     for (int i=0; i<n; i++) {
//         for (int j=i + 1; j<n; j++) {
//             for (int k=j + 1; k<n; k++) {
//                 if (arr[i] + arr[j] + arr[k] == 0) {
//                     vector<int> temp = {arr[i], arr[j], arr[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> result(st.begin(), st.end());
//     return result;
// }


// Alternate method 2 : better
// vector<vector<int>> triplet(int n, vector<int> &arr){
//     set<vector<int>> st;
//     for (int i=0; i<n; i++) {
//         set<int> hashset;
//         for (int j=i + 1; j<n; j++) {
//             int third = -(arr[i] + arr[j]);
//             if (hashset.find(third) != hashset.end()) {
//                 vector<int> temp = {arr[i], arr[j], third};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(arr[j]);
//         }
//     }    
//     vector<vector<int>> result(st.begin(), st.end());
//     return result;
// }


// Alternate method 3 : optimal
vector<vector<int>> triplet(int n, vector<int> &arr){
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    for (int i=0; i<n; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                result.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> result = triplet(n, arr);
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}