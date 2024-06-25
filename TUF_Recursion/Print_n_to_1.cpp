#include <bits/stdc++.h>
using namespace std;

void f(int n) {
    if (n == 0) {
        return;
    }
    cout << n << endl;
    f(n-1);
}

// backtracking
void f2(int i, int n) {
    if (i > n) {
        return;
    }
    f2(i+1, n);
    cout << i << endl;

}

int main() {
    int n;
    cout << "Enter a number :" << endl;
    cin >> n;
    // f(n);
    f2(1, n);
    return 0;
}