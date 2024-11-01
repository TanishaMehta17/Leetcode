#include <bits/stdc++.h>
using namespace std;

int diameter(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    int dia = 0;
    for (int i = 0; i < adj[node].size(); i++) {
        if (!vis[adj[node][i]]) {
            dia = max(dia, 1 + diameter(adj[node][i], adj, vis));
        }
    }
    return dia;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    int u, v;
    while (cin >> u >> v) { 
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    
    int maxDia = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> vis(n + 1, 0);
        int dia = diameter(i, adj, vis);
        maxDia = max(dia, maxDia);
    }
    
    cout << maxDia << endl;
    return 0;
}
