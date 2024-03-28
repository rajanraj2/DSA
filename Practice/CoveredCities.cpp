#include <iostream>
#include <vector>
using namespace std;

int coveredCities(int n, vector<int> &a) {
    if (n == 3) {
        return 0;
    }
    vector<int> distance;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int diff = a[i] - a[i + 1];
        if (diff < 0) {
            diff *= -1;
        }
        sum += diff;
        distance.push_back(diff);
    }
    int sum1 = sum - distance[0] - distance[1];
    int sum2 = sum - distance[n - 2] - distance[n - 3];
    int sum3 = sum - distance[0] - distance[n - 2];

    cout << "Sum1: " << sum1 << ", Sum2: " << sum2 << ", Sum3: " << sum3 << endl;

    if ((sum1 <= sum2) && (sum1 <= sum3)) {
        cout << "Returning Sum1" << endl;
        return sum1;
    } else if (sum2 <= sum3) {
        cout << "Returning Sum2" << endl;
        return sum2;
    } else {
        cout << "Returning Sum3" << endl;
        return sum3;
    }
}

int main() {
    vector<int> a = {-1000, -200000, -10, -344, 100, 3499};
    int result = coveredCities(6, a);
    cout << "Result: " << result << endl;
    return 0;
}
