#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r){
    vector<int> temp;
    int left = l;
    int right = mid+1;
    while (left<=mid && right<=r){
        if (arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
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
    for (int i=l; i<=r; i++){
        arr[i] = temp[i-l];
    }

}

void mergeSort(vector<int> &arr, int l, int r){
    if (l==r){
        return;
    }
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main(){
    int n,x;
    vector<int> arr;
    cout<<"Enter no. of elements: "<<endl;
    cin>>n;
    cout<<"Enter the elements: "<<endl;
    for (int i=0; i<n; i++){
        cin>>x;
        arr.push_back(x);
    }
    mergeSort(arr, 0, n-1);
    cout<<"Sorted array: "<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}