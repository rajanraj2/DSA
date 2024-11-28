// https://leetcode.com/problems/koko-eating-bananas/description/
// Koko eating bananas


class Solution {
private:
    int helper(vector<int>& piles, int& mid, int& h) {
        int ans = 0;
        for (int it : piles) {
            ans += it / mid;
            if (it % mid != 0) ans++; 
            if (ans > h) return ans; 
        }
        return ans;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int result = -1;
        int maxi = *max_element(piles.begin(), piles.end());
        int left = 1, right = maxi;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int hrs = helper(piles, mid, h);
            if (hrs <= h) {
                result = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        } 
        return result;
    }
};