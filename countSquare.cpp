class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int totalSquares = 0;

        // Iterate through the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;  // First row or first column can only form 1x1 squares
                    } else {
                        // Calculate the size of the square submatrix ending at (i, j)
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    totalSquares += dp[i][j];  // Add the number of squares
                }
            }
        }
        return totalSquares;
    }
};