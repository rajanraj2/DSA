#include <bits/stdc++.h>
using namespace std;

// Alternate method 1 : Brute 
// vector<int> rotateArray(vector<int>arr, int k) {
//     int n = arr.size();
//     k = k%n;

//     vector<int> temp;
//     for (int i=0;i<k;i++){
//         temp.push_back(arr[i]);        
//     }
//     for (int i=0;i<n-k;i++){
//         arr[i]=arr[k+i];
//     }
//     for (int i=n-k;i<n;i++){
//         arr[i]=temp[i-(n-k)];
//     }
//     return arr;
// }



// Alternate method 2
// vector<int> rotateArray(vector<int>arr, int k) {
    
//     int n = arr.size();
//     k = k % n; 
//     vector<int> rotatedArr(n);

//     for (int i = 0; i < n; i++) {
//         int newIndex = (i - k + n) % n;
//         rotatedArr[newIndex] = arr[i];
//     }
//     return rotatedArr;
// }



// Alternate method 3
vector<int> rotateArray(vector<int>arr, int k) {
    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());
    reverse(arr.begin(), arr.end());
    return arr;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    vector<int> result = rotateArray(arr, k);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}