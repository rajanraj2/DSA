#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Alternate method 1 : nested loop (all subarrays)

// Alternate method 2 : kadane's algorithm
long long maxSubarraySum(vector<int> arr, int n)
{
    long long maxi = LONG_MIN;
    long long sum =0;
    for (int i=0;i<n;i++){
        // if (sum==0){
        //     int start = i;
        // }
        sum += arr[i];
        if (sum>maxi){
            maxi = sum;
            // int ansStart = start;
            // int end = i;
        }
        if (sum<0){
            sum=0;
        }
    }
    if (maxi<0){
        return 0;
    }
    return maxi;
}

int main() {
    vector<int> v = {1,2,3,-2,5};
    cout << maxSubarraySum(v,5);
    return 0;
}