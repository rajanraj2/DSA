#include <bits/stdc++.h>
using namespace std;

// Alternate method 1 : brute
// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     int n = nums.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             for (int k = j + 1; k < n; k++) {
//                 for (int l = k + 1; l < n; l++) {
//                     if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
//                         vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> result(st.begin(), st.end());
//     return result;
// }


// Alternate method 2 : better
// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     int n = nums.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             set<int> hashset;
//             for (int k = j + 1; k < n; k++) {
//                 hashset.insert(nums[k]);
//                 int forth = target - (nums[i] + nums[j] + nums[k]);
//                 if (hashset.find(forth) != hashset.end()) {
//                     vector<int> temp = {nums[i], nums[j], nums[k], forth};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> result(st.begin(), st.end());
//     return result;
// }


// Alternate method 3 : optimal
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue; 
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i]; 
                sum += nums[j];
                sum += nums[k]; 
                sum += nums[l];
                if (sum < target) {
                    k++;
                }
                else if (sum > target) {
                    l--;
                }
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    result.push_back(temp);
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--; 
                }
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = fourSum(nums, target);
    for (auto v : result) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}