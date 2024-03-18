#include <bits/stdc++.h>
using namespace std;

// Alternate method 1 : check sum for all combinations


// Alternate method 2 : hashing 
// string read(int n, vector<int> book, int target)
// {
//     map<int,int> mpp;
//     for (int i=0;i<n);i++){
//         int a = book[i];
//         int more = target - a;
//         if (mpp.find(more)!=mpp.end()){
//             return "YES";
//         }
//         mpp[a]=i;
//     }
//     return "NO";
// }



// Alternate method 3 : two pointers
string read(int n, vector<int> book, int target){
    int left=0, right=n-1;
    sort(book.begin(), book.end());
    while (left<right){
        int sum = book[left]+book[right];
        if (sum==target){
            return "YES";
        }
        else if (sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return "NO";
}

int main()
{
    int n;
    cin >> n;
    vector<int> book(n);
    for (int i = 0; i < n; i++)
    {
        cin >> book[i];
    }
    int target;
    cin >> target;
    cout << read(n, book, target);
    return 0;
}