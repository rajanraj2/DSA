#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<int> &arr, int n){
    if (arr.empty()){
        return;
    }
    vector<vector<float>> bucket(n);
    int maxN = *max_element(arr.begin(), arr.end());
    for (int i=0; i<n;i++){
        int bucketIndex = n*arr[i]/(maxN + 1);
        bucket[bucketIndex].push_back(arr[i]);
    }

    for (int i=0;i<n;i++){
        sort(bucket[i].begin(), bucket[i].end());
    }

    int index = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<bucket[i].size();j++){
            arr[index++]= bucket[i][j];
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
    bucketSort(arr, n);
    cout<<"Sorted array is : "<<endl;
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}