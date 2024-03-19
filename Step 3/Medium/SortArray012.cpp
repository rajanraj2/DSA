#include <iostream>
#include <vector>
using namespace std;

// Alternate method 1 : nested loop
// Alternate method 2 : count var for 0,1 & 2;
// Alternate method 3 : Dutch national flag algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        while (mid<=high){
            if (nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid]==1){
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2,0,2,1,1,0};
    obj.sortColors(nums);
    for (int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}