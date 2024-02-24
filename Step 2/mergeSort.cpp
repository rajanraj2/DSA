#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    vector<int> temp;
    int left = l;
    int right = mid + 1;
    while (left <= mid && right <=r){
        if (arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while (right<=r){
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = l; i<=r; i++){
        arr[i] = temp[i-l];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l==r){
        return;
    }
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}             

int main() {
    // vector<int> arr;
    int arr[] = {8,7,4,2,5,6,1,3};
    for (int i=0;i<8;i++){
        arr[i] = 8-i;
    }
    mergeSort(arr, 0, 7);
    for (int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}