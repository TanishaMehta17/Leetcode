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

    
    vector<long long> dp(t + 1, 0);
    dp[0] = 1;  

    
    for (int i = 1; i <= t; i++) { 
        for (int j = 0; j < n; j++) {  
            if (i - coins[j] >= 0) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % mod;  
            }
        }
    }

   
    cout << dp[t] % mod << endl;

    return 0;
}
