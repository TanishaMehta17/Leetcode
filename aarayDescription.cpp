#include <bits/stdc++.h>
using namespace std;

int solve(int i, int n, int m, vector<int>& arr, vector<vector<int>>& dp, int prev) {
    if (i >= n) return 0;
    if (i == n - 1) return 1;
    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

    int ways = 0;

    if (arr[i] == 0) {
        for (int k = max(1, prev - 1); k <= min(m, prev + 1); k++) {
            ways += solve(i + 1, n, m, arr, dp, k);
        }
    } else if (prev == -1 || abs(arr[i] - prev) == 1) {
        ways = solve(i + 1, n, m, arr, dp, arr[i]);
    }

    return dp[i][prev + 1] = ways;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(m + 2, -1)); // Using m + 2 for the -1 offset
    int ans = solve(0, n, m, arr, dp, -1);
    cout << ans << endl;
    return 0;
}
