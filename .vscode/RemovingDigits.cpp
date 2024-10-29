#include <bits/stdc++.h>
using namespace std;

vector<int> digitCal(int n) {
    vector<int> digits;
    while (n != 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

int solve(int num, vector<int>& dp) {
    if (num == 0) {
        return 0;
    }

    if (dp[num] != -1) {
        return dp[num];
    }

    int minSteps = INT_MAX;
    vector<int> digits = digitCal(num); 
    for (int d : digits) {
        if (d > 0 && num - d >= 0) {
            minSteps = min(minSteps, 1 + solve(num - d, dp));
        }
    }

    dp[num] = minSteps;
    return dp[num];
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);  
    int result = solve(n, dp);
    
    cout << result << endl;  
    
    return 0;
}