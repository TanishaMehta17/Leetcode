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

void solve(int num, int step, int &minStep, vector<int>& dp) {
    if (num == 0) {
        minStep = min(minStep, step);
        return;
    }
    if (dp[num] != -1) {
        return;
    }

    vector<int> digits = digitCal(num); 
    for (int d : digits) {
        if (d > 0 &&  d <= num) {
            solve(num - d, step + 1, minStep, dp);  
        }
    }

    dp[num] = minStep; 
}

int main() {
    int n;
    cin >> n;
    int step = 0, minStep = INT_MAX;
    vector<int> dp(n + 1, -1);  
    solve(n, step, minStep, dp);  
    cout << minStep << endl;  
    return 0;
}
