#include<bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int>& visited, vector<vector<int>>& adj, vector<int>& ans) {
    visited[node] = 1;
    int cnt = 0;  
    
    for (int nextNode : adj[node]) {
        if (!visited[nextNode]) {
            cnt += 1 + dfs(nextNode, visited, adj, ans);  
        }
    }
    ans[node - 1] = cnt; 
    return cnt;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n - 1); // Storing the parent nodes of each edge
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i];
    }

    vector<vector<int>> adj(n + 1);

   
    for (int i = 2; i <= n; i++) {
        adj[v[i - 2]].push_back(i);
    }

    vector<int> ans(n, 0);       
    vector<int> visited(n + 1, 0); 

   
    dfs(1, visited, adj, ans);

 
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
