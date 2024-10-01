#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, pair<int, int>>> q; 
    string s="";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                q.push({0, {i, j}});
                vis[i][j] = 1;
            }
        }
    }

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1}; 
    int minAns = INT_MAX; 
  
    
    string ans="";
    
    while (!q.empty()) {
        int dis = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        
             
        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            
            if (grid[nrow][ncol] == 'B') {
            minAns = min(minAns, dis+1);
            ans = s; 
            s="";
            continue; 
        }
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '.') {
                vis[nrow][ncol] = 1; 
                if (i == 0)
                    s += 'U';
                else if (i == 1)
                    s += 'R';
                else if (i == 2)
                    s += 'D';
                else if (i == 3)
                    s += 'L';
                
                q.push({dis + 1, {nrow, ncol}});
               // s.pop_back();
            }
        }
        
      
    }
    
    if (minAns == INT_MAX) {
        cout << "No" << endl;
    } else {
        cout << "Yes" <<endl<< minAns << endl<<ans<<endl;
       
    }

    return 0;
}
