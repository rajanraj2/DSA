#include <bits/stdc++.h>
using namespace std;

int subarrayWithMaxProduct(vector<int> &arr){
	int result = INT_MIN;
	int pre = 1, suff = 1;
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		if (pre == 0) pre = 1;
		if (suff == 0) suff = 1;
		pre *= arr[i];
		suff *= arr[n - i - 1];
		result = max(result, max(pre, suff));
	}
	return result;
}

int main(){
    vector<int> arr = {2, 3, -2, 4};
    cout << subarrayWithMaxProduct(arr) << endl;
    return 0;
}