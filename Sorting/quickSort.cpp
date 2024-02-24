#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i<j){
        while (arr[i] <= pivot && i<=high){
            i++;
        }
        while (arr[j] > pivot && j>=low){
            j--;
        }
        if (i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if (low<high){
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
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
    quickSort(arr, 0, n-1);
    cout<<"Sorted array: "<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
