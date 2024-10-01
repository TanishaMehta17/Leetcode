#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& coins, int x) {
    vector<int> dp(x + 1, INT_MAX);  
    dp[0] = 0;  

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);  
            }
        }
    }

    return dp[x] == INT_MAX ? -1 : dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int ans = solve(n, coins, x);
    cout << ans << endl;

    return 0;
}
