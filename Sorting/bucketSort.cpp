#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float> &arr, int n){
    if (arr.empty()){
        return;
    }
    vector<vector<float>> buckets(n);
    int max = *max_element(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++){
        int bucketIndex = n * arr[i] / (max+1);
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++){
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < buckets[i].size(); j++){
            arr[index++] = buckets[i][j];
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin >> n;

    vector<float> arr(n);
    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    bucketSort(arr, n);
    cout<<"Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}