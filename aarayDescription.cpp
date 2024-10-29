#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    if (arr[0] == 0) {
        for (int k = 1; k <= m; ++k) {
            dp[0][k] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; ++i) {
        if (arr[i] == 0) {
            for (int k = 1; k <= m; ++k) {
                dp[i][k] = dp[i - 1][k];
                if (k > 1) dp[i][k] = (dp[i][k] + dp[i - 1][k - 1]) % MOD;
                if (k < m) dp[i][k] = (dp[i][k] + dp[i - 1][k + 1]) % MOD;
            }
        } else {
            dp[i][arr[i]] = dp[i - 1][arr[i]];
            if (arr[i] > 1) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] - 1]) % MOD;
            if (arr[i] < m) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] + 1]) % MOD;
        }
    }

    int ans = 0;
    for (int k = 1; k <= m; ++k) {
        ans = (ans + dp[n - 1][k]) % MOD;
    }

    cout << ans << endl;
    return 0;
}
