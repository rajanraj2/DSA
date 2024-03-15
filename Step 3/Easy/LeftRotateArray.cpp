#include <iostream>
#include <vector>

using namespace std;

vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();
    k = k % n;

    vector<int> temp;
    for (int i = 0; i < k; i++) {
        temp.push_back(arr[i]);
    }
    for (int i = 0; i < n - k; i++) {
        arr[i] = arr[k + i];
    }
    for (int i = n - k; i < n; i++) {
        arr[i] = temp[i - (n - k)];
    }
    return arr;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int k = 3;
    vector<int> result = rotateArray(arr, k);
    for (int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;

}