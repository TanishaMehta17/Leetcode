#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, parent, path;

bool dfs(int node, int start) {
    stack<pair<int, int>> s;
    s.push({node, 0});

    while (!s.empty()) {
        pair<int, int> top = s.top();
        int current = top.first;
        int index = top.second;

        if (vis[current] == 0) {
            vis[current] = 1;
            path.push_back(current);
        }

        while (index < adj[current].size()) {
            int neighbor = adj[current][index++];
            s.top().second = index;

            if (!vis[neighbor]) {
                parent[neighbor] = current;
                s.push({neighbor, 0});
                break;
            } else if (neighbor != parent[current] && neighbor == start) {
                path.push_back(neighbor);
                return true;
            }
        }

        if (index == adj[current].size()) {
            s.pop();
            path.pop_back();
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis.assign(n + 1, 0);
            parent.assign(n + 1, -1);
            path.clear();

            bool cycleFound = dfs(i, i);

            if (cycleFound) {
                cout << path.size() << endl;
                for (int j = 0; j < path.size(); j++) {
                    cout << path[j] << " ";
                }
                cout << endl;
                return 0;
            } 
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
