#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr, int n){
    for (int i=n-1;i>=0;i--){
        for (int j=0; j<i; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}