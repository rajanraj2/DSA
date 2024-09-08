// Link - https://leetcode.com/problems/trapping-rain-water/
// Trapping Rainwater


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        long long total = 0;
        int lMax = 0, rMax = 0, left = 0, right = n - 1;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (lMax > height[left]) {
                    total += lMax - height[left];
                }
                else {
                    lMax = height[left];
                }
                left++;
            }
            else {
                if (rMax > height[right]) {
                    total += rMax - height[right];
                }
                else {
                    rMax = height[right];
                }
                right--;
            }
        }

        return int(total);
    }
};




// Alternate method 

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int total = 0;
//         int n = height.size();
//         int maxi = 0;
//         vector<int> preMax(n), suffMax(n);

//         for (int i = 0; i < n; i++) {
//             maxi = max(maxi, height[i]);
//             preMax[i] = maxi;
//         }

//         maxi = 0;
//         for (int i = n - 1; i >= 0; i--) {
//             maxi = max(maxi, height[i]);
//             suffMax[i] = maxi;
//         }

//         for (int i = 0; i < n; i++) {
//             int leftMax = preMax[i];
//             int rightMax = suffMax[i];
//             if (height[i] < leftMax && height[i] < rightMax) {
//                 total += min(leftMax, rightMax) - height[i];
//             }
//         }

//         return total;
//     }
// };