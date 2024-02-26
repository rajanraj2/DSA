#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countSort(vector<int> &arr, int exp){
    vector<int> output(arr.size());
    vector<int> count(10,0);

    for (int i=0;i<arr.size();i++){
        count[(arr[i]/exp)%10]++;
    }
    for (int i=1;i<10;i++){
        count[i] += count[i-1];
    }
    for (int i=arr.size()-1;i>=0;i--){
        output[(count[(arr[i]/exp)%10])-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for (int i=0;i<arr.size();i++){
        arr[i] = output[i];
    }
}

void radixSort(vector<int> &arr){
    int maxN = *max_element(arr.begin(),arr.end());
    for (int exp=1; maxN/exp>0;exp*=10){
        countSort(arr, exp);
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
    radixSort(arr);
    cout<<"Sorted array is : "<<endl;
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}