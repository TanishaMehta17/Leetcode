#include<bits/stdc++.h>
using namespace std;

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

    vector<int> parent(n + 1, -1);
    vector<int> dist(n + 1, INT_MAX);
    queue<int> q;

    q.push(1);
    dist[1] = 0;
    parent[1] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == n) break;  

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == INT_MAX) {  
                q.push(neighbor);
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;
            }
        }
    }

    if (dist[n] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        for (int node = n; node != -1; node = parent[node]) {
            path.push_back(node);
        }
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}