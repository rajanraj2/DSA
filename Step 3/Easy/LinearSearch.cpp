#include <iostream>
#include <vector>
using namespace std;

int linearSearch(int n, int num, vector<int> &arr)
{
    for (int i=0;i<n;i++){
        if (arr[i]==num){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int num = 4;
    int result = linearSearch(arr.size(), num, arr);
    cout << result << endl;
    return 0;
}