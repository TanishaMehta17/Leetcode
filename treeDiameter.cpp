#include<bits/stdc++.h>
using namespace std;
int diameter()
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    int u, v;
    while (cin >> u >> v) { 
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    return 0;
}