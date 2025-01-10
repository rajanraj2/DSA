// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
// Partitions with given difference


class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target + 1, 00);
        prev[0] = 1;
        if (arr[0] <= target) prev[arr[0]] = 1;
        if (arr[0] == 0) prev[0] = 2;
          
        for (int ind = 1; ind < arr.size(); ind++) {
            vector<int> temp(target + 1, 0);
            temp[0] = 1;
            for (int tar = 0; tar <= target; tar++) {
                int notPick = prev[tar];
                int pick = 0;
                if (arr[ind] <= tar) pick = prev[tar - arr[ind]];
                temp[tar] = pick + notPick;
            }
            prev = temp;
        }
        return prev[target];
    }
      
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int diff = totalSum - d;
        if (diff < 0 || diff % 2) return 0;
        
        return perfectSum(arr, diff / 2);
    }
};
