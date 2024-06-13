// Sliding window (Two pointer approach) :
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char, int> mpp;
        int l = 0, result = 0;
        for (int r = 0; r < n; r++) {
            if (mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l) {
                l = mpp[s[r]] + 1;
            }
            mpp[s[r]] = r;
            result = max(result, r - l + 1);
        }
        return result;
    }
};


// My approach :

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         set<char> myset;
//         map<char, int>  mp;
//         int count = 0, result = 0;
//         for (int i = 0; i < n; i++) {
//             if (myset.find(s[i]) == myset.end()) {
//                 myset.insert(s[i]);
//                 mp[s[i]] = i;
//                 count++;
//             }
//             else {
//                 i = mp[s[i]];
//                 myset.clear();
//                 count = 0;
//             }
//             result = max(result, count);
//         }
//         return result;
//     }
// };