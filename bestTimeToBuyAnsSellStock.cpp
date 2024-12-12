#include <bits/stdc++.h>
using namespace std;

int maxProfit(int i, int n, bool canBuy, vector<int>& v, vector<vector<int>>& dp) {
    if (i >= n)
        return 0;

    if (dp[i][canBuy] != -1)
        return dp[i][canBuy];

    int take = 0, notTake = 0;
    if (canBuy) {
        take = -v[i] + maxProfit(i + 1, n, false, v, dp); // Buy the stock
        notTake = 0 + maxProfit(i + 1, n, true, v, dp);  // Skip buying
    } else {
        take = v[i] + maxProfit(i + 1, n, true, v, dp);  // Sell the stock
        notTake = 0 + maxProfit(i + 1, n, false, v, dp); // Skip selling
    }

    dp[i][canBuy] = max(take, notTake);

    // Debugging: Print dp updates
    cout << "dp[" << i << "][" << canBuy << "] = " << dp[i][canBuy] << endl;

    return dp[i][canBuy];
}

int main() {
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "Invalid input. n must be > 0." << endl;
        return 0;
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Initialize dp array with -1
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << "Maximum Profit: " << maxProfit(0, n, true, v, dp) << endl;

    return 0;
}
