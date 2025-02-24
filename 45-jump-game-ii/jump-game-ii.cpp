class Solution {
private:
    int solve(int i, int n, vector<int>& nums, vector<int>& dp) {
        if (i >= n) return INT_MAX; 
        if (i == n - 1) return 0;   

        if (dp[i] != -1) return dp[i]; 

        int steps = INT_MAX; 

        for (int j = 1; j <= nums[i]; j++) { 
            int nextStep = solve(i + j, n, nums, dp);
            if (nextStep != INT_MAX) {
                steps = min(steps, 1 + nextStep);
            }
        }

        return dp[i] = steps; 
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, n, nums, dp);
    }
};
