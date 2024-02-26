#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int n){
    for (int i=1;i<n;i++){
        int j=i;
        while (j>0 && arr[j]<arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
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
    insertionSort(arr, n);
    cout<<"Sorted array is : "<<endl;
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}