#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    for (int k = 0; k < adj[node].size(); k++) {
        if (!vis[adj[node][k]]) {
            dfs(adj[node][k], adj, vis);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    vector<vector<int>> road;
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int lastComponent = -1;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++;
            if (lastComponent != -1) {
                road.push_back({lastComponent, i});
            }
            lastComponent = i;
            dfs(i, adj, vis);
        }
    }

    cout << cnt - 1 << endl;
    for (int i = 0; i < road.size(); i++) {
        cout << road[i][0] << " " << road[i][1] << endl;
    }

    return 0;
}
