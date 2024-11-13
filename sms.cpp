#include <bits/stdc++.h>
using namespace std;

int solve(int x, int y ,vector<int>& dp) {
    if (x == y)
        return 0;

    if(x<y)
    return INT_MAX;

    if (dp[x]!=-1)
        return dp[x];

    int mini=INT_MAX;

    if (x % 11 == 0 && x / 11 > 0)
       mini= min(mini,1+solve(x / 11, y ,dp));

    if (x % 5 == 0 && x / 5 > 0)
        mini= min(mini,1+solve(x / 5, y, dp));
 
    int remi11=0,remi5=0;
    remi11= x%11;
    remi5= x%5;
   
      if (x + (5 - remi5) >= y) // Prevent x from becoming negative or less than y
    mini = min(mini, 5 - remi5 + solve(x + (5 - remi5), y, dp));

if (x - remi5 >= y) // Prevent x from becoming less than y
    mini = min(mini, remi5 + solve(x - remi5, y, dp));

if (x + (11 - remi11) >= y) // Prevent x from becoming negative or less than y
    mini = min(mini, 11 - remi11 + solve(x + (11 - remi11), y, dp));
    
if (x - remi11 >= y) // Prevent x from becoming less than y
    mini = min(mini, remi11 + solve(x - remi11, y, dp));
    

    return dp[x] =mini;
}

int main() {
    int x, y;
    cin >> x >> y;
    vector<int> dp(1e5,-1);
    int result = solve(x, y, dp);
    cout << result << endl;
    return 0;
}
