#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	int i = 0, j = 1;
  	while (j < n) {
    	if (arr[i] != arr[j]) {
      		arr[++i] = arr[j];
    	}
    	j++;
  	}
  	return i + 1;
}

int main(){
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5};
    int n = arr.size();
    int result = removeDuplicates(arr, n);
    for (int i = 0; i < result; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}