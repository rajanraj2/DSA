// https://www.geeksforgeeks.org/problems/aggressive-cows/0
// Aggressive Cows


class Solution {
  public:
    bool possible(vector<int>& stalls, int mid, int k) {
        int cows = 1;
        int last = stalls[0];
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - last >= mid) {
                cows++;
                last = stalls[i];
            }
            if (cows >= k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int left = 1;
        int right = stalls[n - 1] - stalls[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(stalls, mid, k)) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};