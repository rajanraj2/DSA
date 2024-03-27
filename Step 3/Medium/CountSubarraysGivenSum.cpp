#include <bits/stdc++.h>
using namespace std;

// Alternate method 1
// int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
//     int left = 0, right = 0;
//     int n = arr.size();
//     // // int maxi = INT_MIN;
//     int sum = arr[0];
//     int count = 0;
//     while (right < n) {
//         while (left <= right && sum > k) {
//             sum -= arr[left];
//             left++;
//         }
//         if (sum == k) {
//             count++;
//             // // maxi = max(maxi, right - left + 1);
//         }
//         right++;
//         if (right < n) sum += arr[right];
//     }
//     return count;
// }


// Alternate method 2 
// int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
//     map<int, int> mpp;
//     int n = arr.size();
//     int sum = 0;
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         sum += arr[i];
//         if (sum == k) {
//             count++;
//         }
//         int rem = sum - k;
//         if (mpp.find(rem) != mpp.end()) {
//             count++;
//         } 
//         if (mpp.find(sum) == mpp.end()) {
//             mpp[sum] = i;
//         }
//     }
//     return count;
// }


// Alternate method 3
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int count = 0, preSum = 0;
    map<int, int> mpp;
    mpp[0] = 1;
    for (int i = 0; i < arr.size(); i++) {
        preSum += arr[i];
        int rem = preSum - k;
        count += mpp[rem];
        mpp[preSum]++;
    }
    return count;
}

int main(){
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << findAllSubarraysWithGivenSum(arr, k) << endl;
    return 0;
}