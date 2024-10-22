#include <bits/stdc++.h>
using namespace std;

set<string> unique_combinations;  // To store unique combinations as strings

// Iterative backtracking using a stack
void findCombinations(vector<long long>& coins, long long target) {
    stack<tuple<string, long long, long long>> stk;
    stk.push(make_tuple("", target, 0));

    while (!stk.empty()) {
        string current_combination = get<0>(stk.top());
        long long remaining_target = get<1>(stk.top());
        long long start = get<2>(stk.top());
        stk.pop();

        if (remaining_target == 0) {
            sort(current_combination.begin(), current_combination.end());  // Ensure sorted to avoid duplicates
            unique_combinations.insert(current_combination);  // Store unique combination
            continue;
        }

        for (long long i = start; i < coins.size(); i++) {
            if (coins[i] <= remaining_target) {
                string new_combination = current_combination + to_string(coins[i]) + ',';  // Create combination as a string
                stk.push(make_tuple(new_combination, remaining_target - coins[i], i));  // Explore further
            }
        }
    }
}

int main() {
    long long n, t;
    cin >> n >> t;

    vector<long long> coins(n);
    for (long long i = 0; i < n; i++) {
        cin >> coins[i];
    }

    findCombinations(coins, t);

    // Output the number of unique combinations
    cout << unique_combinations.size() << endl;

    return 0;
}
