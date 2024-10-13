#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int t, vector<vector<int>>& adj, vector<int>& team, vector<int>& vis) {
    vis[node] = 1;
    team[node] = t;

    for (auto it : adj[node]) {
        if (team[it] == t) {
            return false; 
        }
        if (!vis[it]) {
            if (!dfs(it, !t, adj, team, vis)) {
                return false;  
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);  
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> team(n + 1, -1); 
      vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (!dfs(i, 1, adj, team, vis)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;  
            }
        }
    }

   
    for (int i = 1; i <= n; i++) {
        if (team[i] == 0)
            cout << 2 << " ";
        else
            cout << 1 << " ";
    }
    cout << endl;

    return 0;
}
