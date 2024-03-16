#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> &a, int n){
    int largest = a[0];
    int sLargest = -1;
    for (int i=1;i<n;i++){
        if (a[i]>largest){
            sLargest = largest;
            largest = a[i];
        }
        else if (a[i]<largest && a[i]>sLargest){
            sLargest = a[i];
        }
    }
    return sLargest;
}

int secondSmallest(vector<int> &a, int n){
    int smallest = a[0];
    int sSmallest = INT_MAX;
    for (int i=1;i<n;i++){
        if (a[i]<smallest){
            sSmallest = smallest;
            smallest = a[i];
        }
        else if (a[i]>smallest && a[i]<sSmallest){
            sSmallest = a[i];
        }
    }
    return sSmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int sLargest = secondLargest(a, n);
    int sSmallest = secondSmallest(a, n);
    return {sLargest, sSmallest};
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();
    vector<int> result = getSecondOrderElements(n, a);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}