#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> ans(nums.size(), 0);
//         int posIndex = 0, negIndex = 1;
//         for (int i=0; i<nums.size(); i++){
//             if (nums[i] < 0){
//                 ans[negIndex] = nums[i];
//                 negIndex+=2;
//             }
//             else {
//                 ans[posIndex] = nums[i];
//                 posIndex+=2;
//             }
//         }
//         return ans;
//     }
// };

// int main() {
//     Solution sol;
//     vector<int> v = {-1, 2, -3, 4, 5, -6, -7, -8, 9, 10};
//     vector<int> ans = sol.rearrangeArray(v);
//     for (int i=0; i<ans.size(); i++){
//         cout << ans[i] << " ";
//     }
//     return 0;
// }


// variety 2 of the same problem

vector<int> alternateNumbers(vector<int>&a) {
    vector<int> pos, neg;
    int n = a.size();
    for (int i=0; i<n; i++){
        if (a[i]<0){
            neg.push_back(a[i]);
        }
        else {
            pos.push_back(a[i]);
        }
    }
    if (pos.size()>neg.size()){
        for (int i=0; i<neg.size(); i++){
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = 2 * neg.size();
        for (int i=neg.size(); i<pos.size(); i++){
            a[index] = pos[i];
            index++;
        }
    }
    else {
        for (int i=0; i<pos.size(); i++){
            a[2*i] = pos[i];
            a[2*i +1] = neg[i];
        }
        int index = 2 * pos.size();
        for (int i=pos.size(); i<neg.size(); i++){
            a[index] = neg[i];
            index++;
        }
    }
    return a;
}

int main() {
    vector<int> v = {-1, 2, -3, 4, 5, 6, -7, 8, 9, 10};
    vector<int> ans = alternateNumbers(v);
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}

