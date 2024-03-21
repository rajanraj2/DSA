#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int bestTimeToBuyAndSellStock(vector<int>&prices) {
    int mini = prices[0];
    int maxProfit = 0;
    for (int i=1; i < prices.size(); i++){
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}

int main() {
    vector<int> v = {7,1,5,3,6,4};
    cout << bestTimeToBuyAndSellStock(v);
    return 0;
}