#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int l, int r){
    int pivot = l;
    int i = l;
    int j = r;
    while (i<j){
        while (arr[i]<=arr[pivot] && i<=r){
            i++;
        }
        while (arr[j]>arr[pivot] && j>=l){
            j--;
        }
        if (i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[pivot], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int l, int r){
    if (l<r){
        int pIndex = partition(arr, l, r);
        quickSort(arr, l, pIndex - 1);
        quickSort(arr, pIndex + 1, r);
    }
}

int main(){
    int n,x;
    cout<< "Enter no. of elements: "<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the elements: "<<endl;
    for (int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    quickSort(arr, 0, n-1);
    cout<<"Sorted array is : "<<endl;
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}