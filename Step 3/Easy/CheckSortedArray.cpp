#include <bits/stdc++.h>
using namespace std;

int isSorted(int n, vector<int> a) {
    for (int i=0;i<n-1;i++){
        if (a[i]<=a[i+1]){

        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();
    int result = isSorted(n, a);
    cout << result;
    return 0;
}