// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Capacity To Ship Packages Within D Days


class Solution {
private:
    bool possible(vector<int>& weights, int mid, int days) {
        int day = 1, load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > mid) {
                day++;
                load = weights[i];
            }
            else load += weights[i];
        }
        if (day <= days) return true;
        else return false;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(weights, mid, days)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};