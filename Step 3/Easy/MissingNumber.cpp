#include <iostream>
#include <vector>
using namespace std;

// Alternate method 1 : nested loop
// Alternate method 2 : hashing
// Alternate method 3 : sum 
// Alternate method 4 : xor (optimal)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            xor2 = xor2 ^ nums[i];
            xor1 = xor1 ^ (i+1);  
        }
        return xor1 ^ xor2;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,0,1};
    cout << s.missingNumber(nums) << endl;
    return 0;
}