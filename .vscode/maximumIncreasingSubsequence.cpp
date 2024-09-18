#include <bits/stdc++.h>
using namespace std;

int max_sum_inc_sub_helper(int i, int n, vector<int>& a, vector<int>& dp) {
    // Base case: The subsequence ending at index i has at least one element, which is a[i].
    if (dp[i] != -1) 
        return dp[i];

    int max_sum = a[i]; // At least the element itself

    // Check all previous elements and find the max sum subsequence ending at i
    for (int j = 0; j < i; j++) {
        if (a[i] > a[j]) {
            max_sum = max(max_sum, a[i] + max_sum_inc_sub_helper(j, n, a, dp));
        }
    }

    return dp[i] = max_sum;
}

int solve(int n, vector<int>& a) {
    vector<int> dp(n, -1);
    int ans = 0;

    // Calculate the maximum sum increasing subsequence ending at each index
    for (int i = 0; i < n; i++) {
        ans = max(ans, max_sum_inc_sub_helper(i, n, a, dp));
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_sum = solve(n, a);
    cout << max_sum << endl;

    return 0;
}
