#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left=0, right=0;
    long long sum=a[0];
    int maxi = 0;
    int n = a.size();
    while (right<n){
        while (left<=right && sum>k){
            sum -= a[left];
            left++;
        }
        if (sum==k){
            maxi = max(maxi, right-left+1);
        }
        right++;
        if (right < n) sum+=a[right];
    }
    return maxi;
}

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    long long k = 15;
    cout << longestSubarrayWithSumK(a, k) << endl;
    return 0;
}