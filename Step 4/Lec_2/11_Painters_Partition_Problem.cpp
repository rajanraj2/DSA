// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?leftPanelTabValue=PROBLEM
// Painter's Partition Problem


#include <bits/stdc++.h>

bool possible(vector<int>& nums, int mid, int k) {
    int sum = 0, count = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (sum + nums[i] <= mid) sum += nums[i];
        else {
            sum = nums[i];
            count++;
        }
    }
    if (count > k) return false;
    return true;
}

int findLargestMinDistance(vector<int> &nums, int k)
{
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (possible(nums, mid, k)) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}