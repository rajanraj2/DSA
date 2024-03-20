#include <iostream>
#include <vector>
using namespace std;

// Alternate method 1 : nested loop


// Alternate method 2 : hashing
// int majorityElement(vector<int> v) {
// 	map<int,int> mpp;
// 	for (int i=0;i<v.size();i++){
// 		mpp[v[i]]++;
// 	}
// 	for (auto it : mpp){
// 		if (it.second>(v.size()/2)){
// 			return it.first;
// 		}
// 	}
// 	return -1;
// }


// Alternate method 3 : moore's voting algorithm
int majorityElement(vector<int> v) {
	int el;
	int cnt = 0;
	int count=0;
	for (int i=0;i<v.size();i++){
		if (cnt==0){
			el = v[i];
			cnt++;
		}
		else if (el==v[i]){
			cnt++;
		}
		else{
			cnt--;
		}
	}
	// code to check if there's a majority element in the array or not
	// for (auto it:v){
	// 	if (it==el){
	// 		count++;
	// 	}
	// }
	// if (count>(v.size()/2)){
	// 	return el;
	// }
	// else {
	// 	return -1;
	// }
	return el;
}

int main() {
    vector<int> v = {3,3,4,2,4,4,2,4,4};
    cout << majorityElement(v);
    return 0;
}