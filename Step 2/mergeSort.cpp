#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while (left<<mid && right<<high){
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
    while (right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for (int i=low; i<high; i++){
        arr[i] = temp[i];
    }
}

void ms(vector<int> &arr, int low, int high){
    if (low==high){
        return;
    }
    int mid = (low + high)/2;
    ms(arr, low, mid);
    ms(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> arr, int n){
    ms(arr, 0, n-1);
}

int main() {
    vector<int> arr;
    // arr = [8,7,4,2,5,6,1,3];
    for (int i=0;i<8;i++){
        arr[i] = 8-i;
    }
    mergeSort(arr, 8);
    for (int i=0;i<8;i++){
        cout<<arr[i];
    }
    return 0;
}