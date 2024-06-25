#include <bits/stdc++.h>
using namespace std;

void f(int n, int original) {
    if (n == 0) {
        return;
    }
    
    cout << n << endl;
    f(n-1, original);  // Recursive call to count down
    
    // This part simulates backtracking by counting back up
    if (n != original) {
        cout << " : " <<  n << endl;
    }
}

int main() {
    int n;
    cout << "Enter a number :" << endl;
    cin >> n;
    f(n, n);  // Pass the original value of n as well
    return 0;
}
