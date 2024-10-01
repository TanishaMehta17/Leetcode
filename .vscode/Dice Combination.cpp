#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
vector<long long> dp;  // Memoization table

// Recursive function with memoization
long long solve(int t) {
    if (t == 0) return 1;    // Base case: If target is 0, there is 1 way to achieve it
    if (t < 0) return 0;     // Base case: If target is negative, no valid way

    // If result is already computed, return it
    if (dp[t] != -1) return dp[t];

    long long ways = 0;
    // Consider taking any number between 1 and 6
    for (int i = 1; i <= 6; i++) {
        ways = (ways + solve(t - i)) % mod;
    }

    // Store the computed result
    return dp[t] = ways;
}

int main() {
    int n;
    cin >> n;

    // Initialize dp table with -1 for memoization (uncomputed)
    dp.resize(n + 1, -1);

    // Start the recursion with the target sum `n`
    cout << solve(n) << endl;

    return 0;
}
