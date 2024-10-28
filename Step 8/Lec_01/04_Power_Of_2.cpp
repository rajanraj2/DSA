// Link - https://leetcode.com/problems/power-of-two/
// Power of two


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        long x = n;
        return (x & (x - 1)) == 0;
    }
};


// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         int count = 0;
//         while (n) {
//             if ((n & 1)) count++;
//             if (count >= 2) break;
//             n = n >> 1;
//         }
//         if (count == 1) return true;
//         return false;
//     }
// };