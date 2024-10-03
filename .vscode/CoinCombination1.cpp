#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Initialize dp array with 0
    vector<long long> dp(t + 1, 0);
    dp[0] = 1;  // Base case: one way to make sum 0 (by taking no coins)

    // Fill the dp array using tabulation
    for (int i = 1; i <= t; i++) {  // Loop through all possible target sums
        for (int j = 0; j < n; j++) {  // Loop through the coins
            if (i - coins[j] >= 0) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % mod;  // Use the result of smaller subproblems
            }
        }
    }

    // Output the result for the target sum
    cout << dp[t] % mod << endl;

    return 0;
}
