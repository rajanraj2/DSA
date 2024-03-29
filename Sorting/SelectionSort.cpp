#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr, int n){
    for (int i=0; i<n-1; i++){
        int mini = i;
        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
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
    selectionSort(arr, n);
    cout << "Sorted array: ";
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}