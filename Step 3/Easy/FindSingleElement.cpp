#include <bits/stdc++.h>
using namespace std;

// int getSingleElement(vector<int> &arr){
// 	int result = 0;
//     for (int i=0; i<arr.size(); i++) {
//         result = result ^ arr[i];
//     }
//     return result;
// }

int getSingleElement(vector<int> &arr){
	int ans = 0;
    for(int i=1;i<arr.size();i = i+2){
       if(arr[i-1]!= arr[i]){
             ans = arr[i-1];
             return ans;
        }
    }
    return arr[arr.size()-1];
}

int main(){
    vector<int> arr = {4,1,2,1,2};
    cout << getSingleElement(arr) << endl;
    return 0;
}