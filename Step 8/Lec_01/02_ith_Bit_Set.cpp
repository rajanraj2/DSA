// Link - https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
// K-th bit is set or not


class Solution {
  public:
    bool checkKthBit(int n, int k) {
        return (n & (1 << k)) ? true : false;
    }
};