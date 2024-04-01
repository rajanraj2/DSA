#include <bits/stdc++.h>
using namespace std;

// Alternate method 1 : brute force


// Alternate method 2 : better 
// vector<int> majorityElement(vector<int> v) {
// 	int n = v.size();
// 	int mini = n/3 + 1;
// 	vector<int> result;
// 	map<int, int> mpp;
// 	for (int i=0; i < n; i++) {
// 		mpp[v[i]]++;
// 		if (mpp[v[i]] == mini) {
// 			result.push_back(v[i]);
// 		}
// 		if (result.size() == 2){
// 			break;
// 		}
// 	}
// 	sort(result.begin(), result.end());
// 	return result;
// }


// Alternate method 3 : optimal 
vector<int> majorityElement(vector<int> v) {
	int cnt1 = 0, cnt2 = 0;
	int el1 = INT_MIN, el2 = INT_MIN;
	int n = v.size();
	int mini = n/3 + 1;
	vector<int> result;
	for (int i = 0; i < n; i++) {
		if (cnt1 == 0 && el2 != v[i]) {
			cnt1 = 1;
			el1 = v[i];
		}
		else if (cnt2 == 0 && el1 != v[i]) {
			cnt2 = 1;
			el2 = v[i];
		}
		else if (el1 == v[i]) cnt1++;
		else if (el2 == v[i]) cnt2++;
		else  {
			cnt1--;
			cnt2--;
		}
	}
	cnt1 = 0, cnt2 = 0;
	for (int i=0; i < n; i++) {
		if (el1 == v[i]) cnt1++;
		if (el2 == v[i]) cnt2++;
	}
	if (cnt1 >= mini) result.push_back(el1);
	if (cnt2 >= mini) result.push_back(el2);
	sort(result.begin(), result.end());
	return result;
}

int main() {
    vector<int> v = {3, 2, 3, 3, 3, 2, 2, 5, 6, 2, 7, 3, 2};
    vector<int> result = majorityElement(v);
    for (int i=0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout<<endl;
    return 0;
}