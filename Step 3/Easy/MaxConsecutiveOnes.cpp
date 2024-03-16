#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int count = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]!=1){
                maxi = max(count, maxi);
                count = 0;
            }
            else {
                count++;
            }
        }
        return max(count, maxi);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,0,1,1,1};
    cout << s.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}