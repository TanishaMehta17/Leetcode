class Solution {
private:
    int solve(int i, int j, int m, int n, vector<int>& drow, vector<int>& dcol, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int take = 0;
        for (int k = 0; k < 3; ++k) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] > grid[i][j]) {
                take = max(take, 1 + solve(nrow, ncol, m, n, drow, dcol, grid, dp));
            }
        }
        
        return dp[i][j] = take;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<int> drow = {-1, 0, 1};
        vector<int> dcol = {1, 1, 1};
        int maxi = 0;

      
        for (int i = 0; i < m; ++i) {
            maxi = max(maxi, solve(i, 0, m, n, drow, dcol, grid, dp));
        }

        return maxi;
    }
};
