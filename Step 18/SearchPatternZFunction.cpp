#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        for (int i = 0; i < m - n + 1; i++) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
        }   
        return -1;
    }
};

int main() {
    string haystack = "hello";
    string needle = "ll";
    Solution obj;
    cout << obj.strStr(haystack, needle) << endl;
    return 0;
}