// Link - https://www.geeksforgeeks.org/problems/graph-and-vertices/1

class Solution {
  public:
    long long count(int n) {
        // your code here
        long long result = n * (n - 1)/2;
        return pow(2,result);
    }
};