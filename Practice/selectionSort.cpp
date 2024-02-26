#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr, int n){
    for (int i=0;i<n;i++){
        int mini = i;
        for (int j=i;j<n;j++){
            if (arr[j]<arr[mini]){
                mini = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
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
    selectionSort(arr, n);
    cout<<"Sorted array is : "<<endl;
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}