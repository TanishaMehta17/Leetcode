#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    int a, b;
    vector<int> ans(n + 1);

    for (int i = 0; i < n - 1; i++) { // n-1 edges for a connected tree
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i}); // Start from node `i` with distance 0
        vector<int> vis(n + 1, 0);
        vis[i] = 1;
        
        int maxDist = 0; // Track the farthest distance from node `i`
        
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            maxDist = max(maxDist, dis);

            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    pq.push({dis + 1, neighbor});
                }
            }
        }
        ans[i] = maxDist; // Store the farthest distance for node `i`
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
