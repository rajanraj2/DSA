#include <bits/stdc++.h>
using namespace std;

// Alternate method 1
// vector<int> moveZeros(int n, vector<int> a) {
//     vector<int> temp;
//     for (int i=0;i<n;i++){
//         if (a[i]!=0){
//             temp.push_back(a[i]);
//         }
//     }
//     for (int i=0;i<temp.size();i++){
//         a[i]=temp[i];
//     }
//     for (int i=temp.size();i<n;i++){
//         a[i]=0;
//     }
//     return a;
// }


// Alternate method 2
vector<int> moveZeros(int n, vector<int> a) {
    int j=-1;
    for (int i=0;i<n;i++){
        if (a[i]==0){
            j=i;
            break;
        }
    }

    if (j==-1) return a;

    for (int i=j+1;i<n;i++){
        if (a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }
    return a;
}

int main(){
    vector<int> a = {1, 0, 2, 0, 3, 0, 4, 0, 5};
    vector<int> result = moveZeros(a.size(), a);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}