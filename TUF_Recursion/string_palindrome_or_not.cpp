#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (s[start] != s[end]) {
        return false;
    }
    return isPalindrome(s, start + 1, end - 1);
}


int main() {
    string s;
    cout << "Enter a string :" << endl;
    cin >> s;
    int start = 0;
    int end = s.size() - 1;
    if (isPalindrome(s, start, end)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}